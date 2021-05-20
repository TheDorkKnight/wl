#ifndef WL_PLAYER_LOCATIONS_H
#define WL_PLAYER_LOCATIONS_H

#include <cstdint>
#include <cassert>
#include <array>
#include <wl/wl.h>
#include <wl/investigator_id.h>

namespace wl {

class PlayerLocations {
	using Location = MapNode::ID;

	std::array<Location,3> investigator_locations_;
	Location               jack_location_;

public:
	constexpr PlayerLocations(MapNode::ID i0_loc,
		                      MapNode::ID i1_loc,
		                      MapNode::ID i2_loc,
		                      MapNode::ID jack_loc) noexcept
		: investigator_locations_{i0_loc, i1_loc, i2_loc}
		, jack_location_{jack_loc}
	{}

	constexpr MapNode::ID investigator_location(InvestigatorID id) const noexcept {
		switch (id) {
		case InvestigatorID::ZERO: return std::get<0>(investigator_locations_);
		case InvestigatorID::ONE:  return std::get<1>(investigator_locations_);
		case InvestigatorID::TWO:  break;
		}
		return std::get<2>(investigator_locations_);
	}
	constexpr MapNode::ID jack_location() const noexcept { return jack_location_; }

	void move_investigator(InvestigatorID id, MapNode::ID to_location) noexcept {
		switch (id) {
		case InvestigatorID::ZERO: std::get<0>(investigator_locations_) = to_location; break;
		case InvestigatorID::ONE:  std::get<1>(investigator_locations_) = to_location; break;
		case InvestigatorID::TWO:  std::get<2>(investigator_locations_) = to_location; break;
		}
	}
	void move_jack(MapNode::ID to_location) noexcept {
		jack_location_ = to_location;
	}
};

} // namespace

#endif
