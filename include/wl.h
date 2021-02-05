#ifndef WL_H
#define WL_H

#include <vector>
#include <cstdint>
#include <variant>
#include <optional>
#include <span>

namespace wl {

class JackNode {
public:
	using ID = std::uint8_t;
	using WaterBodyID = std::uint8_t;

private:
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
		WaterBodyID water_body_id_ = 0;
	public:
		constexpr bool can_drop_evidence() const noexcept {
			return false;
		}

		constexpr std::optional<WaterBodyID> water_body_id() const noexcept {
			return water_body_id_;
		}
	};
	using Type = std::variant<Normal,NoEvidence,Water>;
	Type            type_{ Normal{} };
	std::vector<ID> neighbors_{};
public:
	JackNode(std::vector<ID> nbors) noexcept
		: neighbors_{ std::move(nbors) }
		, type_{ Normal{} }
	{}

	JackNode(std::vector<ID> nbors,
		     NoEvidence no_evidence) noexcept
		: neighbors_{ std::move(nbors) }
		, type_{ std::move(no_evidence) }
	{}

	JackNode(std::vector<ID> nbors,
		     Water water) noexcept
		: neighbors_{ std::move(nbors) }
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

	std::span<const ID> neighbors() const noexcept { return neighbors_; }
};

// jid_from_label
constexpr JackNode::ID jid(std::uint8_t label_id) noexcept {
	return label_id - 1;
}

class InvestigatorNode {
public:
	using ID = std::uint8_t;

private:
	bool                      starting_position_ = false;
	std::vector<ID>           neighbors_{};
	std::vector<JackNode::ID> jack_node_neighbors_{};
public:
	InvestigatorNode(std::vector<ID> nbors,
		             std::vector<JackNode::ID> jack_nbors,
		             bool is_starting_pos = false) noexcept
		: neighbors_{ std::move(nbors) }
		, jack_node_neighbors_{ std::move(jack_nbors) }
		, starting_position_{ is_starting_pos }
	{}

	std::span<const ID> neighbors() const noexcept
	{ return neighbors_; }

	std::span<const JackNode::ID> jack_neighbors() const noexcept
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
