#ifndef WL_H
#define WL_H

#include <vector>
#include <cstdint>
#include <variant>
#include <optional>
#include <span>

#include "tagged_id.h"

namespace wl {

class JackNode {
public:
	struct JackTag{};
	struct WaterBodyTag{};
	using ID = TaggedID<JackTag>;
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
		constexpr bool can_drop_evidence() const noexcept {
			return false;
		}

		constexpr std::optional<WaterBodyID> water_body_id() const noexcept {
			return water_body_id_;
		}
	};
private:
	using Type = std::variant<Normal,NoEvidence,Water>;
	Type                type_{ Normal{} };
	std::span<const ID> neighbors_{};
public:
	constexpr JackNode(std::span<const ID> nbors) noexcept
		: neighbors_{ nbors }
		, type_{ Normal{} }
	{}

	constexpr JackNode(std::span<const ID> nbors,
		     NoEvidence no_evidence) noexcept
		: neighbors_{ nbors }
		, type_{ std::move(no_evidence) }
	{}

	constexpr JackNode(std::span<const ID> nbors,
		     Water water) noexcept
		: neighbors_{ nbors }
		, type_{ std::move(water) }
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

	constexpr std::span<const ID> neighbors() const noexcept { return neighbors_; }
};

// jid_from_label
constexpr JackNode::ID jid(std::uint8_t label_id) noexcept {
	return JackNode::ID{static_cast<std::uint8_t>(label_id - 1)};
}

// jid_from_label
constexpr std::uint8_t jid_to_label(JackNode::ID id) noexcept {
	return static_cast<std::uint8_t>(id) + 1;
}

class InvestigatorNode {
public:
	struct InvestigatorTag{};
	using ID = TaggedID<InvestigatorTag>;

private:
	bool                          starting_position_ = false;
	std::span<const ID>           neighbors_{};
	std::span<const JackNode::ID> jack_node_neighbors_{};
public:
	constexpr InvestigatorNode(std::span<const ID> nbors,
		                       std::span<const JackNode::ID> jack_nbors,
		                       bool is_starting_pos = false) noexcept
		: neighbors_{ nbors }
		, jack_node_neighbors_{ jack_nbors }
		, starting_position_{ is_starting_pos }
	{}

	constexpr std::span<const ID> neighbors() const noexcept
	{ return neighbors_; }

	constexpr std::span<const JackNode::ID> jack_neighbors() const noexcept
	{ return jack_node_neighbors_; }

	constexpr bool is_starting_position() const noexcept {
		return starting_position_;
	}
};

class MapGraph {
	std::vector<JackNode>         jack_nodes_;
	std::vector<InvestigatorNode> investigator_nodes_;
public:
	MapGraph(std::vector<JackNode> j_nodes,
		     std::vector<InvestigatorNode> i_nodes)
		: jack_nodes_{ std::move(j_nodes) }
		, investigator_nodes_{ std::move(i_nodes) }
	{}

	std::span<const JackNode> jack_nodes() const noexcept
	{ return jack_nodes_; }

	std::span<const InvestigatorNode> investigator_nodes() const noexcept
	{ return investigator_nodes_; }
};

} // namespace wl

#endif
