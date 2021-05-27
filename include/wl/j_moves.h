#ifndef WL_J_MOVES_H
#define WL_J_MOVES_H

#include <cstdint>
#include <cassert>
#include <array>
#include <optional>
#include <wl/wl.h>
#include <wl/jack_inventory.h>

namespace wl {

class JackMove {
	MapNode::ID where_to_;
	std::optional<JackResource> resource_;

public:
	constexpr JackMove(MapNode::ID whereto) noexcept
		: where_to_{ whereto }
		, resource_{ std::nullopt }
	{}
	constexpr JackMove(MapNode::ID whereto, JackResource move_cost) noexcept
		: where_to_{ whereto }
		, resource_{ move_cost }
	{}

	constexpr MapNode::ID destination() const noexcept { return where_to_; }
	constexpr std::optional<JackResource> cost() const noexcept { return resource_; }

	constexpr bool operator==(const JackMove& other) const noexcept {
		return (where_to_ == other.where_to_) &&
		       (resource_ == other.resource_);
	}
	constexpr bool operator!=(const JackMove& other) const noexcept {
		return !(*this == other);
	}

	constexpr bool operator<(const JackMove& other) const noexcept {
		return (where_to_ < other.where_to_) ||
			   (   (where_to_ == other.where_to_) &&
			       (resource_ < other.resource_));
	}
};

} // namespace

#endif

