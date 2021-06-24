#ifndef WL_FIND_J_MOVES_H
#define WL_FIND_J_MOVES_H

#include <vector>
#include <wl/wl.h>
#include <wl/game_state.h>
#include <wl/j_moves.h>

namespace wl {

inline std::vector<JackMove> available_normal_jack_moves(const GameState& game_state,
	                                                     const History& game_history,
	                                                     const MapGraph& map_graph) {
	const MapNode::ID current_jack_position = game_state.jack_location();

	struct ExplorationFrame {
		MapNode::ID node_id;
		std::span<const MapNode::Adjacency> remaining_adjacencies;
	};

	std::vector<MapNode::ID> visited_nodes;
	std::vector<ExplorationFrame> exploration_stack;

	const auto have_visited = [&visited_nodes] (MapNode::ID id) -> bool {
		const auto end = visited_nodes.cend();
		return std::find(visited_nodes.cbegin(), end, id) != end;
	};

	// prime the exploration stack with Jack's current position
	exploration_stack.emplace_back(ExplorationFrame{
		current_jack_position,
		map_graph.map_node(current_jack_position).neighbors()});
	visited_nodes.push_back(current_jack_position);

	std::vector<JackMove> results;
	while (!exploration_stack.empty()) {
		ExplorationFrame& frame = exploration_stack.back();

		// if we are done exploring this node, then go back to where we were before
		if (frame.remaining_adjacencies.empty()) {
			exploration_stack.pop_back();
			continue;
		}

		// get the current adjacency
		const MapNode::Adjacency adjacency =
			frame.remaining_adjacencies.back();
		// and remove it from the list of remaining adjacencies
		frame.remaining_adjacencies =
			frame.remaining_adjacencies.first(
				frame.remaining_adjacencies.size() - 1);

		// check if we've been here before, or if this is a non-traversable
		// water adjacency
		if (adjacency.is_water_border() || have_visited(adjacency.id())) {
			continue;
		}
		// otherwise add it to the list of places we've been
		visited_nodes.emplace_back(adjacency.id());

		// now we know we are visiting a new node
		if (map_graph.is_jack_node(adjacency.id())) {
			// this is a Jack node, so it is a valid normal move location
			results.push_back(JackMove{adjacency.id()});
			continue;
		}

		// we are visiting an Investigator node
		if (game_state.has_investigator_at_location(adjacency.id())) {
			continue;
		}

		// otherwise explore this node (ie. add a stack frame for this node)
		exploration_stack.emplace_back(ExplorationFrame{
			adjacency.id(),
		    map_graph.map_node(adjacency.id()).neighbors()});
	}
	return results;
}

inline std::vector<MapNode::ID> jack_neighs_of(const MapNode::ID current_jack_position,
	const MapGraph& map_graph) {

	struct ExplorationFrame {
		MapNode::ID node_id;
		std::span<const MapNode::Adjacency> remaining_adjacencies;
	};

	std::vector<MapNode::ID> visited_nodes;
	std::vector<ExplorationFrame> exploration_stack;

	const auto have_visited = [&visited_nodes](MapNode::ID id) -> bool {
		const auto end = visited_nodes.cend();
		return std::find(visited_nodes.cbegin(), end, id) != end;
	};

	// prime the exploration stack with Jack's current position
	exploration_stack.emplace_back(ExplorationFrame{
		current_jack_position,
		map_graph.map_node(current_jack_position).neighbors() });
	visited_nodes.push_back(current_jack_position);

	std::vector<MapNode::ID> results;
	while (!exploration_stack.empty()) {
		ExplorationFrame& frame = exploration_stack.back();

		// if we are done exploring this node, then go back to where we were before
		if (frame.remaining_adjacencies.empty()) {
			exploration_stack.pop_back();
			continue;
		}

		// get the current adjacency
		const MapNode::Adjacency adjacency =
			frame.remaining_adjacencies.back();
		// and remove it from the list of remaining adjacencies
		frame.remaining_adjacencies =
			frame.remaining_adjacencies.first(
				frame.remaining_adjacencies.size() - 1);

		// check if we've been here before, or if this is a non-traversable
		// water adjacency
		if (adjacency.is_water_border() || have_visited(adjacency.id())) {
			continue;
		}
		// otherwise add it to the list of places we've been
		visited_nodes.emplace_back(adjacency.id());

		// now we know we are visiting a new node
		if (map_graph.is_jack_node(adjacency.id())) {
			// this is a Jack node, so it is a valid normal move location
			results.push_back(adjacency.id());
			continue;
		}

		// otherwise explore this node (ie. add a stack frame for this node)
		exploration_stack.emplace_back(ExplorationFrame{
			adjacency.id(),
			map_graph.map_node(adjacency.id()).neighbors() });
	}
	return results;
}

inline std::vector<JackMove> available_carriage_jack_moves(const GameState& game_state,
	                                                       const History& game_history,
	                                                       const MapGraph& map_graph) {
	
	//Get the jack neighs of jakes current node, except if discovery location
	const auto jack_neighs = jack_neighs_of(game_state.jack_location(), map_graph);
	//for each jack neigh, get all of its jack neighs, except if discovery lcoation
	std::vector<MapNode::ID> all_neigh_neighs;
	for (const auto& jack_neigh : jack_neighs) {
		if (game_state.is_discovery_location(jack_neigh)) {
			continue;
		}
		const auto jack_neigh_neighs = jack_neighs_of(jack_neigh, map_graph);
		std::copy(jack_neigh_neighs.begin(), jack_neigh_neighs.end(), std::back_inserter(all_neigh_neighs));
	}
	std::sort(all_neigh_neighs.begin(), all_neigh_neighs.end());
	const auto newend = std::unique(all_neigh_neighs.begin(), all_neigh_neighs.end());
	all_neigh_neighs.erase(newend, all_neigh_neighs.end());
	all_neigh_neighs.erase(std::find(all_neigh_neighs.begin(), all_neigh_neighs.end(), game_state.jack_location()));
	std::vector<JackMove> carriage_moves;
	carriage_moves.reserve(all_neigh_neighs.size());
	for (const auto& neigh_neigh : all_neigh_neighs) {
		if (game_state.is_discovery_location(neigh_neigh)) {
			continue;
		}
		carriage_moves.push_back(JackMove{ neigh_neigh, JackResource::CARRIAGE });
	}
	return carriage_moves;
}

inline std::vector<JackMove> available_alley_jack_moves(const GameState& game_state,
	                                                    const History& game_history,
	                                                    const MapGraph& map_graph) {
	// TODO: really implement
	return std::vector<JackMove>{};
}

inline std::vector<JackMove> available_boat_jack_moves(const GameState& game_state,
	                                                   const History& game_history,
	                                                   const MapGraph& map_graph) {
	// TODO: really implement
	return std::vector<JackMove>{};
}

// Returns the set of possible jack moves given the game state
inline std::vector<JackMove> available_jack_moves(const GameState& game_state,
	                                              const History& game_history,
	                                              const MapGraph& map_graph) {
	std::vector<JackMove> moves = available_normal_jack_moves(game_state, game_history, map_graph);
	const auto carriage_moves = available_carriage_jack_moves(game_state, game_history, map_graph);
	const auto alley_moves = available_alley_jack_moves(game_state, game_history, map_graph);
	const auto boat_moves = available_boat_jack_moves(game_state, game_history, map_graph);

	moves.reserve(moves.size() +
		          carriage_moves.size() +
		          alley_moves.size() +
		          boat_moves.size());
	auto moves_back_inserter = std::back_inserter(moves);
	std::copy(carriage_moves.begin(), carriage_moves.end(), moves_back_inserter);
	std::copy(alley_moves.begin(), alley_moves.end(), moves_back_inserter);
	std::copy(boat_moves.begin(), boat_moves.end(), moves_back_inserter);
	return moves;
}

} // namespace wl

#endif
