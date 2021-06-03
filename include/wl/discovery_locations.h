#ifndef WL_DISCOVERY_LOCATIONS_H
#define WL_DISCOVERY_LOCATIONS_H

#include <cstdint>
#include <cassert>
#include <array>
#include <wl/wl.h>

namespace wl {

class DiscoveryLocations {
	std::array<MapNode::ID,4> locations_;

public:
	using iterator = std::array<MapNode::ID,4>::const_iterator;

	constexpr DiscoveryLocations(MapNode::ID loc0,
	                             MapNode::ID loc1,
	                             MapNode::ID loc2,
	                             MapNode::ID loc3) noexcept
		: locations_{loc0, loc1, loc2, loc3}
	{}

	constexpr iterator begin() const noexcept { return locations_.begin(); }
	constexpr iterator end() const noexcept { return locations_.end(); }
	constexpr auto size() const noexcept { return locations_.size(); }
};

} // namespace

#endif
