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

private:
	// neighbors must be specified in clockwise order
	std::span<const ID> neighbors_{};

	constexpr auto find_neighbor(ID nbor) const noexcept {
		return std::find(neighbors_.begin(), neighbors_.end(), nbor);
	}

public:
	constexpr MapNode(std::span<const ID> nbors) noexcept : neighbors_{nbors} {}

	constexpr std::span<const ID> neighbors() const noexcept { return neighbors_; }

	constexpr std::optional<ID> neighbor_counter_clockwise_of(ID nbor) const noexcept {
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

	constexpr std::optional<ID> neighbor_clockwise_of(ID nbor) const noexcept {
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
	static constexpr std::size_t num_nodes_total = 70u; // should be 189u;

	struct JackTag{};
	struct WaterBodyTag{};
	using WaterBodyID = TaggedID<WaterBodyTag>;

	struct Normal{
		constexpr bool can_drop_evidence() const noexcept {
			return true;
		}
		constexpr std::optional<WaterBodyID> water_body_id() const noexcept {
			return std::nullopt;
		}
	};
	struct NoEvidence{
		constexpr bool can_drop_evidence() const noexcept {
			return false;
		}
		constexpr std::optional<WaterBodyID> water_body_id() const noexcept {
			return std::nullopt;
		}
	};
	class Water {
		WaterBodyID water_body_id_{ static_cast<std::uint8_t>(0u) };
	public:
		constexpr Water(WaterBodyID wbody_id) noexcept
			: water_body_id_{ wbody_id }
		{}

		constexpr bool can_drop_evidence() const noexcept {
			return false;
		}

		constexpr WaterBodyID id() const noexcept { return water_body_id_; }
		constexpr std::optional<WaterBodyID> water_body_id() const noexcept {
			return id();
		}
	};
private:
	using Type = std::variant<Normal,NoEvidence,Water>;
	Type        type_{ Normal{} };

public:
	constexpr JackNode(Normal normal = Normal{}) noexcept
		: type_{ std::move(normal) }
	{}

	constexpr JackNode(NoEvidence no_evidence) noexcept
		: type_{ std::move(no_evidence) }
	{}

	constexpr JackNode(Water water) noexcept
		: type_{ std::move(water) }
	{}

	constexpr bool can_drop_evidence() const {
		return std::visit(
			[](const auto& t)
			{
				return t.can_drop_evidence();	
			}, type_);
	}

	constexpr std::optional<WaterBodyID> water_body_id() const {
		return std::visit(
			[](const auto& t)
			{
				return t.water_body_id();	
			}, type_);
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
