#include <map>
#include <algorithm>
#include <initializer_list>
#include <gtest/gtest.h>
#include <wl/game_state.h>
#include <wl/find_j_moves.h>
#include <wl/default_map.h>

namespace wl {
std::ostream& operator<<(std::ostream& os, JackResource resource) {
	switch (resource) {
	case JackResource::CARRIAGE: os << "CARRIAGE"; break;
	case JackResource::ALLEY: os << "ALLEY"; break;
	case JackResource::BOAT: os << "BOAT"; break;
	}
	return os;
}

std::ostream& operator<<(std::ostream& os, JackMove move) {
	os << "JackMove{destination:" << static_cast<size_t>(move.destination());
	if (const auto cost = move.cost(); cost.has_value()) {
		os << ",cost:" << *cost;
	}
	os << "}";
	return os;
}
} // namespace wl

namespace {
const wl::MapGraph k_default_map = wl::default_map();


void do_normal_moves_test(std::initializer_list<wl::JackMove> expected_moves,
	                      const wl::GameState& game_state,
	                      const wl::History& history)
{
	// setup a map to keep track of which expected moves we found
	std::map<wl::JackMove, bool> expected_moves_found;
	for (const wl::JackMove expected_move : expected_moves) {
		expected_moves_found.emplace(expected_move, false);
	}
	ASSERT_EQ(expected_moves_found.size(), expected_moves.size());

	// find the moves
	const auto found_moves = available_normal_jack_moves(game_state, history, k_default_map);
	EXPECT_EQ(expected_moves_found.size(), found_moves.size());

	// check that all moves found were expected
	for (const wl::JackMove move : found_moves) {
		auto itr = expected_moves_found.find(move);
		if (itr == expected_moves_found.end()) {
			FAIL() << "found unexpected move: " << move;
			continue;
		}
		// note that we found this move
		itr->second = true;
	}

	// check that all expected moves were found
	for (const auto& keyval : expected_moves_found) {
		if (!keyval.second) {
			FAIL() << "did not find expected move: " << keyval.first;
		}
	}
}

void do_carriage_moves_test(std::initializer_list<wl::JackMove> expected_moves,
	const wl::GameState& game_state,
	const wl::History& history)
{
	// setup a map to keep track of which expected moves we found
	std::map<wl::JackMove, bool> expected_moves_found;
	for (const wl::JackMove expected_move : expected_moves) {
		expected_moves_found.emplace(expected_move, false);
	}
	ASSERT_EQ(expected_moves_found.size(), expected_moves.size());

	// find the moves
	const auto found_moves = available_carriage_jack_moves(game_state, history, k_default_map);
	EXPECT_EQ(expected_moves_found.size(), found_moves.size());

	// check that all moves found were expected
	for (const wl::JackMove move : found_moves) {
		auto itr = expected_moves_found.find(move);
		if (itr == expected_moves_found.end()) {
			FAIL() << "found unexpected move: " << move;
			continue;
		}
		// note that we found this move
		itr->second = true;
	}

	// check that all expected moves were found
	for (const auto& keyval : expected_moves_found) {
		if (!keyval.second) {
			FAIL() << "did not find expected move: " << keyval.first;
		}
	}
}

} // namespace

TEST(FindJackMoves, simple_normal_moves) {
	// Make a game state. Not trying to involve investigators, so put them all in a corner.
	// Don't give Jack any cards.
	constexpr wl::MapNode::ID jack_location = wl::map_id(66);
	constexpr wl::PlayerLocations player_locations{wl::map_id(189), wl::map_id(190), wl::map_id(191), jack_location};
	const wl::GameState game_state{
		player_locations,
		wl::DiscoveryLocations{wl::map_id(173), wl::map_id(11), wl::map_id(64), wl::map_id(132)},
		wl::InvestigatorAbilities{},
		wl::JackInventory{0,0,0} // no jack cards
	};
	const wl::History history{};

	// Here, Jack only has two options, each from the same stem i node (232).
	//
	//   *              *
	// (j64)--(i232)--(j67)
	//          |
	//        (j66) <- jack is here
	do_normal_moves_test(
		{
			wl::JackMove{wl::map_id(64)},
			wl::JackMove{wl::map_id(67)}
		},
		game_state,
		history);
}

TEST(FindJackMoves, normal_moves_through_multiple_i_nodes) {
	// Make a game state. Not trying to involve investigators, so put them all in a corner.
	// Don't give Jack any cards.
	constexpr wl::MapNode::ID jack_location = wl::map_id(8);
	constexpr wl::PlayerLocations player_locations{wl::map_id(202), wl::map_id(203), wl::map_id(204), jack_location};
	const wl::GameState game_state{
		player_locations,
		wl::DiscoveryLocations{wl::map_id(173), wl::map_id(11), wl::map_id(64), wl::map_id(132)},
		wl::InvestigatorAbilities{},
		wl::JackInventory{0,0,0} // no jack cards
	};
	const wl::History history{};

	// Here we test that Jack is able to reach nodes through more than one i node,
	// namely via the routes of either j008->i189->i207->somewhere or j008->i206->i207->somewhere
	//
	// jack    (j001)*
	//   V        |
	// (j008)--(i189)--(j009)*
	//    |       |
	// (i206)--(i207)--(j010)* 
	//    |       |
	// (j028)  (j029)
	//    *       *
	do_normal_moves_test(
		{
			wl::JackMove{wl::map_id(1)},
			wl::JackMove{wl::map_id(9)},
			wl::JackMove{wl::map_id(10)},
			wl::JackMove{wl::map_id(29)},
			wl::JackMove{wl::map_id(28)}
		},
		game_state,
		history);
}

TEST(FindJackMoves, normal_moves_stopped_by_investigator) {
	// Make a game state. Put an investigator on node i189 to block Jack
	// Don't give Jack any cards.
	constexpr wl::MapNode::ID jack_location = wl::map_id(8);
	constexpr wl::PlayerLocations player_locations{wl::map_id(189), wl::map_id(203), wl::map_id(204), jack_location};
	const wl::GameState game_state{
		player_locations,
		wl::DiscoveryLocations{wl::map_id(173), wl::map_id(11), wl::map_id(64), wl::map_id(132)},
		wl::InvestigatorAbilities{},
		wl::JackInventory{0,0,0} // no jack cards
	};
	const wl::History history{};

	// Here we test that Jack is able to reach nodes through more than one i node,
	// even if an investigator is blocking one of his routes to that node.
	// Namely he shall go via the route of either j008->i206->i207->somewhere
	//
	// jack    (j001) ,- investigator here
	//   V        |  /
	// (j008)-x(i189)--(j009)
	//    |       X
	// (i206)--(i207)--(j010)* 
	//    |       |
	// (j028)  (j029)
	//    *       *
	do_normal_moves_test(
		{
			wl::JackMove{wl::map_id(10)},
			wl::JackMove{wl::map_id(29)},
			wl::JackMove{wl::map_id(28)}
		},
		game_state,
		history);
}

TEST(FindJackMoves, normal_carriage_moves) {
	// Make a game state.
	// Give Jack 1 carriage tile.
	// Add investogators inside test network 
	constexpr wl::MapNode::ID jack_location = wl::map_id(7);
	constexpr wl::PlayerLocations player_locations{ wl::map_id(217), wl::map_id(201), wl::map_id(205), jack_location };
	const wl::GameState game_state{
		player_locations,
		wl::DiscoveryLocations{wl::map_id(173), wl::map_id(11), wl::map_id(64), wl::map_id(132)},
		wl::InvestigatorAbilities{},
		wl::JackInventory{1,0,0} // 1 jack cards
	};
	const wl::History history{};

	// Here we test that Jack is able to reach nodes through more than one i node,
	// even if an investigator is blocking one of his routes to that node.
	// Investigators at * locations
    //
    // (j006)--*(i201)--(j025)--(i202) 
    //           |        |       | 
    //           |        |     (j007) <--Jack Here
    //           |        |       |
    //           |     (i203)--(i204)--(j027)
    //           |        |       |       |
    //           |        |    (j026)--(i205)* 
    //           |        |       |       | 
    //        *(i217)--(j045)--(i218)  (j047)
    //	         |        |
    //         (j024)  (j046)
	do_carriage_moves_test(
		{
			wl::JackMove{wl::map_id(25),wl::JackResource::CARRIAGE},
			wl::JackMove{wl::map_id(6),wl::JackResource::CARRIAGE},
			wl::JackMove{wl::map_id(26),wl::JackResource::CARRIAGE},
			wl::JackMove{wl::map_id(27),wl::JackResource::CARRIAGE},
			wl::JackMove{wl::map_id(45),wl::JackResource::CARRIAGE},
			wl::JackMove{wl::map_id(46),wl::JackResource::CARRIAGE},
			wl::JackMove{wl::map_id(47),wl::JackResource::CARRIAGE},
			wl::JackMove{wl::map_id(24),wl::JackResource::CARRIAGE}
		},
		game_state,
		history);
}