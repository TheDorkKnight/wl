#ifndef WL_H
#define WL_H

#include <cassert>
#include <vector>
#include <cstdint>
#include <variant>
#include <optional>
#include <span>
#include <algorithm>

#include "tagged_id.h"

namespace wl {

class MapNode {
	struct Tag{};
public:
	using ID = TaggedID<Tag, std::uint16_t>;

	class Adjacency {
		ID id_         = ID{ 0u };
		bool is_water_ = false;
	public:
		struct WaterBorder{};

		constexpr Adjacency(ID neighbor_id) noexcept
			: id_{neighbor_id}
			, is_water_{ false }
		{}
		constexpr Adjacency(ID neighbor_id, WaterBorder) noexcept
			: id_{ neighbor_id }
			, is_water_{ true }
		{}

		constexpr ID id() const noexcept { return id_; }
		constexpr bool is_water_border() const noexcept { return is_water_; }
	};

private:
	// neighbors must be specified in clockwise order
	std::span<const Adjacency> neighbors_{};

	constexpr auto find_neighbor(ID nbor) const noexcept {
		return std::find_if(neighbors_.begin(), neighbors_.end(),
			[nbor](const auto& adjacency) noexcept -> bool {
				return adjacency.id() == nbor;
			});
	}

public:
	constexpr MapNode(std::span<const Adjacency> nbors) noexcept : neighbors_{nbors} {}

	constexpr std::span<const Adjacency> neighbors() const noexcept { return neighbors_; }

	constexpr std::optional<Adjacency> neighbor_counter_clockwise_of(ID nbor) const noexcept {
		auto nbor_itr = find_neighbor(nbor);
		if (nbor_itr == neighbors_.end()) {
			return std::nullopt;
		}
		// now decrement by one, since neighbors are in clockwise order
		if (nbor_itr == neighbors_.begin()) {
			// note that we are guaranteed at least size() >= 1, since
			// we found a the neighbour. Return last neighbour in list.
			nbor_itr = (neighbors_.end() - 1);
		} else {
			--nbor_itr;
		}
		return *nbor_itr;
	}

	constexpr std::optional<Adjacency> neighbor_clockwise_of(ID nbor) const noexcept {
		auto nbor_itr = find_neighbor(nbor);
		if (nbor_itr == neighbors_.end()) {
			return std::nullopt;
		}
		// now increment by one, since neighbors are in clockwise order
		++nbor_itr;
		if (nbor_itr == neighbors_.end()) {
			// wrap around to beginning
			nbor_itr = neighbors_.begin();
		}
		return *nbor_itr;
	}
};

constexpr MapNode::ID map_id(std::uint16_t label_id) noexcept {
	return MapNode::ID{static_cast<std::uint16_t>(label_id)};
}

constexpr std::uint16_t map_id_to_label(MapNode::ID id) noexcept {
	return static_cast<std::uint16_t>(id);
}

class JackNode {
public:
	static constexpr std::size_t num_nodes_total = 180u; // should be 189u;

	enum class Type : std::uint8_t {
		Normal,
		NoEvidence,
		Water
	};

private:
	Type type_ = Type::Normal;

public:
	constexpr JackNode(Type t = Type::Normal) noexcept
		: type_{ t }
	{}

	constexpr bool can_drop_evidence() const {
		return type_ == Type::Normal;
	}

	constexpr bool is_water() const noexcept {
		return type_ == Type::Water;
	}
};

class InvestigatorNode {
public:
	static constexpr std::size_t num_nodes_total = 0u; // so far

private:
	bool starting_position_ = false;

public:
	constexpr InvestigatorNode(bool is_starting_pos) noexcept
		: starting_position_{ is_starting_pos }
	{}

	constexpr bool is_starting_position() const noexcept {
		return starting_position_;
	}
};

class MapGraph {
public:
	static constexpr std::size_t num_jack_nodes = JackNode::num_nodes_total;
	static constexpr std::size_t num_investigator_nodes = InvestigatorNode::num_nodes_total;
	static constexpr std::size_t num_nodes_total = num_jack_nodes + num_investigator_nodes;

private:
	std::span<const MapNode, num_nodes_total>                 map_nodes_;
	std::span<const JackNode, num_jack_nodes>                 jack_nodes_;
	std::span<const InvestigatorNode, num_investigator_nodes> investigator_nodes_;

public:
	constexpr MapGraph(std::span<const MapNode, num_nodes_total> m_nodes,
		               std::span<const JackNode, num_jack_nodes> j_nodes,
		               std::span<const InvestigatorNode, num_investigator_nodes> i_nodes) noexcept
		: map_nodes_{ m_nodes }
		, jack_nodes_{ j_nodes }
		, investigator_nodes_{ i_nodes }
	{
		// TODO: check map validity?
	}

	constexpr MapNode::ID base_jack_node_id() const noexcept { return MapNode::ID{0u}; }
	constexpr MapNode::ID base_investigator_node_id() const noexcept {
		static_assert(num_jack_nodes <= std::numeric_limits<std::uint16_t>::max());
		return MapNode::ID{static_cast<std::uint16_t>(num_jack_nodes)};
	}

	constexpr const MapNode& map_node(MapNode::ID id) const noexcept {
		assert(static_cast<std::size_t>(id) < num_nodes_total);
		return map_nodes_[static_cast<std::size_t>(id)];
	}

	constexpr bool is_jack_node(MapNode::ID id) const noexcept {
		return static_cast<std::size_t>(id) < num_jack_nodes;
	}

	// REQUIRED: is_jack_node(id) is true
	constexpr const JackNode& jack_node(MapNode::ID id) const noexcept {
		assert(is_jack_node(id));
		return jack_nodes_[static_cast<std::size_t>(id)];
	}

	// REQUIRED: is_jack_node(id) is false
	constexpr const InvestigatorNode& investigator_node(MapNode::ID id) const noexcept {
		assert(!is_jack_node(id));
		const std::size_t investigator_node_index =
			static_cast<std::size_t>(id) - static_cast<std::size_t>(base_investigator_node_id());
		assert(investigator_node_index < num_investigator_nodes);
		return investigator_nodes_[investigator_node_index];
	}

	std::span<const MapNode, num_nodes_total> map_nodes() const noexcept
	{ return map_nodes_; }

	std::span<const JackNode, num_jack_nodes> jack_nodes() const noexcept
	{ return jack_nodes_; }

	std::span<const InvestigatorNode, num_investigator_nodes> investigator_nodes() const noexcept
	{ return investigator_nodes_; }
};

} // namespace wl

#endif
