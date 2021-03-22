#ifndef WL_BLOCK_ITERATOR_H
#define WL_BLOCK_ITERATOR_H

#include <iterator>
#include <array>
#include <wl/wl.h>

namespace wl {

class ClockwiseBlockIterator {
	MapNode::ID last_node_id_    = MapNode::ID{ 0u };
	MapNode::ID current_node_id_ = MapNode::ID{ 0u };
	const MapGraph* map_graph_   = nullptr;
	bool as_begin_               = true;

	auto find_adjacency(MapNode::ID from, MapNode::ID to, const MapGraph& graph) const {
		const MapNode& from_node = graph.map_node(from);
		const auto nbors = from_node.neighbors();
		return std::find_if(
			nbors.begin(),
			nbors.end(),
			[to](const MapNode::Adjacency& adjacency) noexcept -> bool { return adjacency.id() == to; });
	}

public:
	using value_type = MapNode::ID;
	using pointer = const MapNode::ID*;
	using reference = value_type;
	using iterator_category = std::input_iterator_tag;

	ClockwiseBlockIterator(MapNode::ID prev_neighbor_node_id, 
		                   MapNode::ID start_node_id,
		                   const MapGraph& graph,
		                   bool as_begin_iterator) noexcept
		: last_node_id_{ prev_neighbor_node_id }
		, current_node_id_{ start_node_id }
		, map_graph_{&graph}
		, as_begin_{ as_begin_iterator }
	{
		assert(find_adjacency(start_node_id, prev_neighbor_node_id, graph) != map_graph_->map_node(start_node).neighbors().end());
	}

	value_type operator*() const noexcept {
		return current_node_id_;
	}

	pointer operator->() const noexcept {
		return &current_node_id_;
	}

	ClockwiseBlockIterator& operator++() {
		as_begin_ = false;
		const auto& node = map_graph_->map_node(current_node_id_);
		if (node.neighbors().size() == 1u) {
			// double-back on spikes like:
			// 
			// ( 4 )---( 2^)---( 1 )    ^: last node
			//           |              *: current node
			//         ( 3*)
			// 
			// ie. transition to:
			//
			// ( 4*)---( 2^)---( 1 )    ^: last node
			//           |              *: current node
			//         ( 3 )
			//
			// skipping re-visit of node 2
			const auto& last_node = map_graph_->map_node(last_node_id_);
			const auto next_adjacency = last_node.neighbor_clockwise_of(current_node_id_);
			assert(next_adjacency.has_value());
			current_node_id_ = next_adjacency->id();
			return *this;
		}
		const auto next_adjacency = node.neighbor_counter_clockwise_of(last_node_id_);
		last_node_id_ = current_node_id_;
		assert(next_adjacency.has_value());
		current_node_id_ = next_adjacency->id();
		return *this;
	}

	bool operator==(const ClockwiseBlockIterator& other) const noexcept {
		assert(map_graph_ == other.map_graph_);
		return (last_node_id_ == other.last_node_id_) &&
			   (current_node_id_ == other.current_node_id_) &&
			   (as_begin_ == other.as_begin_);
	}
	bool operator!=(const ClockwiseBlockIterator& other) const noexcept {
		assert(map_graph_ == other.map_graph_);
		return (last_node_id_ != other.last_node_id_) ||
			   (current_node_id_ != other.current_node_id_) ||
			   (as_begin_ != other.as_begin_);
	}
};

class ClockwiseBlock {
	ClockwiseBlockIterator begin_;
	ClockwiseBlockIterator end_;
public:
	using iterator = ClockwiseBlockIterator;

	ClockwiseBlock(MapNode::ID prev_neighbor, MapNode::ID starting_node, const MapGraph& graph)
		: begin_{prev_neighbor, starting_node,  graph, true}
		, end_{prev_neighbor, starting_node, graph, false}
	{}

	iterator begin() const { return begin_; }
	iterator end() const { return end_; }
};

} // namespace wl

#endif // WL_BLOCK_ITERATOR_H
