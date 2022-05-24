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

template <class FindMovesFunc>
void do_moves_test(std::initializer_list<wl::JackMove> expected_moves,
	               const wl::GameState& game_state,
	               const wl::History& history,
	               FindMovesFunc&& find_moves)
{
	// setup a map to keep track of which expected moves we found
	std::map<wl::JackMove, bool> expected_moves_found;
	for (const wl::JackMove expected_move : expected_moves) {
		expected_moves_found.emplace(expected_move, false);
	}
	ASSERT_EQ(expected_moves_found.size(), expected_moves.size());

	// find the moves
	const auto found_moves = find_moves(game_state, history, k_default_map);
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


void do_normal_moves_test(std::initializer_list<wl::JackMove> expected_moves,
	                      const wl::GameState& game_state,
	                      const wl::History& history)
{
	do_moves_test(std::forward<std::initializer_list<wl::JackMove>>(expected_moves),
		game_state,
		history,
		wl::available_normal_jack_moves);
}

void do_carriage_moves_test(std::initializer_list<wl::JackMove> expected_moves,
	const wl::GameState& game_state,
	const wl::History& history)
{
	do_moves_test(std::forward<std::initializer_list<wl::JackMove>>(expected_moves),
		game_state,
		history,
		wl::available_carriage_jack_moves);
}

void do_alley_moves_test(std::initializer_list<wl::JackMove> expected_moves,
	const wl::GameState& game_state,
	const wl::History& history)
{
	do_moves_test(std::forward<std::initializer_list<wl::JackMove>>(expected_moves),
		game_state,
		history,
		wl::available_alley_jack_moves);
}

void do_boat_moves_test(std::initializer_list<wl::JackMove> expected_moves,
	const wl::GameState& game_state,
	const wl::History& history)
{
	do_moves_test(std::forward<std::initializer_list<wl::JackMove>>(expected_moves),
		game_state,
		history,
		wl::available_boat_jack_moves);
}

void do_all_moves_test(std::initializer_list<wl::JackMove> expected_moves,
	const wl::GameState& game_state,
	const wl::History& history)
{
	do_moves_test(std::forward<std::initializer_list<wl::JackMove>>(expected_moves),
		game_state,
		history,
		wl::available_jack_moves);
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

TEST(FindJackMoves, only_alley_moves) {
	// Make a game state.
	// Give Jack 1 alley tile.
	// Add investigators blocking other moves
	constexpr wl::MapNode::ID jack_location = wl::map_id(163);
	constexpr wl::PlayerLocations player_locations{ wl::map_id(332), wl::map_id(323), wl::map_id(333), jack_location };
	const wl::GameState game_state{
		player_locations,
		wl::DiscoveryLocations{wl::map_id(173), wl::map_id(11), wl::map_id(64), wl::map_id(132)},
		wl::InvestigatorAbilities{},
		wl::JackInventory{0,1,0} // 1 alley card
	};
	const wl::History history{};

	// Here we test that Jack is able to reach any other j-node on each of the two blocks
	// adjacent to his current location, despite that fact that he is hemmed-in by investigators
	// for all of his normal move locations. Investigators at * locations
	//
    //      |                             |
    //   (i322)----------(j162)--------(i323)
    //      |                             |
    //      |         BLOCK   Jack     (j164)
    //      |                  v          |
    //   (j161)----(i332)*---(j163)----(i333)*-
    //      |       |                     |
    //           (j178)       BLOCK    (j180)
    //              |                     |
    //           (i340)-----(j179)-----(i341)--
    //
    // We expect that he should be able to reach each location prefixed with j and
    // pictured in this map.
	do_alley_moves_test(
		{
			wl::JackMove{wl::map_id(161),wl::JackResource::ALLEY},
			wl::JackMove{wl::map_id(162),wl::JackResource::ALLEY},
			wl::JackMove{wl::map_id(164),wl::JackResource::ALLEY},
			wl::JackMove{wl::map_id(178),wl::JackResource::ALLEY},
			wl::JackMove{wl::map_id(179),wl::JackResource::ALLEY},
			wl::JackMove{wl::map_id(180),wl::JackResource::ALLEY}
		},
		game_state,
		history);
}

TEST(FindJackMoves, only_boat_moves) {
	// Make a game state.
	// Give Jack 1 boat tile.
	// Add investigators blocking other moves
	constexpr wl::MapNode::ID jack_location = wl::map_id(113);
	constexpr wl::PlayerLocations player_locations{ wl::map_id(349), wl::map_id(350), wl::map_id(275), jack_location };
	const wl::GameState game_state{
		player_locations,
		wl::DiscoveryLocations{wl::map_id(173), wl::map_id(11), wl::map_id(64), wl::map_id(132)},
		wl::InvestigatorAbilities{},
		wl::JackInventory{0,0,1} // 1 boat card
	};
	const wl::History history{};

	// Here we test that Jack is able to reach any other j-node in the same water block
	// adjacent to his current location, despite that fact that he is hemmed-in by investigators
	// for all of his normal move locations. Investigators at * locations
	//
    //      \ /                                            |
    //  --(i284)--(i285)--(j94)--(i275)*-(j79)--(i249)--(i250)--
    //       |       |              |             |        |
    //       |    (j111)W        (j95)W         (j80)W     |
    //       |                                             |
    //    (j112)               WATER BLOCK               (j97)
    //       |                                             |
    //       |  Jack is here --> (j113)W    (j96)W         |
    //       |                      |          |           |
    //  --(i348)------(j114)-----(i349)*----(i350)*-----(i351)--
    //       |                                             |
    //
    // We expect that he should be able to reach each location prefixed with j and
    // suffixed with W (for "water") pictured in this map.
	do_boat_moves_test(
		{
			wl::JackMove{wl::map_id(80),wl::JackResource::BOAT},
			wl::JackMove{wl::map_id(95),wl::JackResource::BOAT},
			wl::JackMove{wl::map_id(96),wl::JackResource::BOAT},
			wl::JackMove{wl::map_id(111),wl::JackResource::BOAT}
		},
		game_state,
		history);
}

TEST(FindJackMoves, boat_and_carriage_moves) {
	// Make a game state.
	// Give Jack 1 carriage tile and 1 boat tile.
	// Add investigators blocking other moves
	constexpr wl::MapNode::ID jack_location = wl::map_id(113);
	constexpr wl::PlayerLocations player_locations{ wl::map_id(349), wl::map_id(350), wl::map_id(275), jack_location };
	const wl::GameState game_state{
		player_locations,
		wl::DiscoveryLocations{wl::map_id(173), wl::map_id(11), wl::map_id(67), wl::map_id(171)},
		wl::InvestigatorAbilities{},
		wl::JackInventory{1,0,1} // 1 carriage and 1 boat card
	};
	const wl::History history{};

	// Here we test that Jack is able to reach any other j-node in the same water block
	// adjacent to his current location AND any j-node 1 or 2 hops away, despite the fact
	// that he is hemmed-in by investigators for all of his normal move locations.
	// Investigators at * locations
	//                                                                           |      
	//                                                                       --(J46)--
	//                                                                           |
	//                                                                        (i231)--(J65)--
    //                            \ /                                            |
    //                        --(i284)--(i285)--(j94)--(i275)*-(J79)--(i249)--(i250)--(J64)--
    //                             |       |              |             |        |
    //                             |    (j111)W        (j95)W         (J80)W     |
    //                             |                                             |
    //                          (J112)               WATER BLOCK               (J97)
    //                             |                                             |
    //                  (J131)W    |  Jack is here --> (j113)W    (J96)W         |
    //                     |       |                      |          |           |
    //--(J145)--(i346)--(i347)--(i348)------(J114)-----(i349)*----(i350)*-----(i351)--(J98)W
    //             |               |                      |                      |
    //          (J147)          (J132)                 (J115)                    |
    //             |               |                      |                      |
    //                                ------(J133)-----(i352)-----------------(J116)
    //
    // We expect that he should be able to reach each location prefixed with j and
    // suffixed with W (for "water") pictured in this map, or any location with
    // a capital J by carriage.
	do_all_moves_test(
		{
			wl::JackMove{wl::map_id(80),wl::JackResource::BOAT},
			wl::JackMove{wl::map_id(95),wl::JackResource::BOAT},
			wl::JackMove{wl::map_id(96),wl::JackResource::BOAT},
			wl::JackMove{wl::map_id(111),wl::JackResource::BOAT},
			wl::JackMove{wl::map_id(46),wl::JackResource::CARRIAGE},
			wl::JackMove{wl::map_id(64),wl::JackResource::CARRIAGE},
			wl::JackMove{wl::map_id(65),wl::JackResource::CARRIAGE},
			wl::JackMove{wl::map_id(79),wl::JackResource::CARRIAGE},
			wl::JackMove{wl::map_id(80),wl::JackResource::CARRIAGE},
			wl::JackMove{wl::map_id(96),wl::JackResource::CARRIAGE},
			wl::JackMove{wl::map_id(97),wl::JackResource::CARRIAGE},
			wl::JackMove{wl::map_id(98),wl::JackResource::CARRIAGE},
			wl::JackMove{wl::map_id(112),wl::JackResource::CARRIAGE},
			wl::JackMove{wl::map_id(114),wl::JackResource::CARRIAGE},
			wl::JackMove{wl::map_id(115),wl::JackResource::CARRIAGE},
			wl::JackMove{wl::map_id(116),wl::JackResource::CARRIAGE},
			wl::JackMove{wl::map_id(131),wl::JackResource::CARRIAGE},
			wl::JackMove{wl::map_id(132),wl::JackResource::CARRIAGE},
			wl::JackMove{wl::map_id(133),wl::JackResource::CARRIAGE},
			wl::JackMove{wl::map_id(145),wl::JackResource::CARRIAGE},
			wl::JackMove{wl::map_id(147),wl::JackResource::CARRIAGE}
		},
		game_state,
		history);
}
