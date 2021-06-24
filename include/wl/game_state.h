#ifndef WL_GAME_STATE_H
#define WL_GAME_STATE_H

#include <wl/wl.h>
#include <wl/discovery_locations.h>
#include <wl/player_locations.h>
#include <wl/investigator_abilities.h>
#include <wl/j_moves.h>

namespace wl {

struct History{}; // TODO

class GameState {
	PlayerLocations       player_locations_;
	DiscoveryLocations    discovery_locations_;
	InvestigatorAbilities investigator_abilities_;
	JackInventory         jack_inventory_;

public:
	constexpr GameState(PlayerLocations starting_locations,
		                DiscoveryLocations discovery_locations,
		                InvestigatorAbilities starting_abilities,
		                JackInventory starting_jack_inventory) noexcept
		: player_locations_{std::move(starting_locations)}
		, discovery_locations_{std::move(discovery_locations)}
		, investigator_abilities_{std::move(starting_abilities)}
		, jack_inventory_{std::move(starting_jack_inventory)}
	{}

	// note: accounts for "double-moves" when using a carriage
	std::uint8_t moves_made_by_jack_since_last_discovery() const;

	bool has_investigator_at_location(MapNode::ID node_id) const noexcept {
		return player_locations_.has_investigator_at_location(node_id);
	}
	bool is_discovery_location(MapNode::ID node_id) const noexcept {
		return discovery_locations_.contains(node_id);
	}
	MapNode::ID jack_location() const noexcept {
	 	return player_locations_.jack_location();
	}
};

} // namespace

#endif
