#ifndef WL_BLOCK_ITERATOR_H
#define WL_BLOCK_ITERATOR_H

#include <iterator>
#include <wl/wl.h>

namespace wl {

// Iterator over all adjacencies in a particular block. See ClockwiseBlock for usage.
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
	using difference_type = std::ptrdiff_t;
	using iterator_category = std::input_iterator_tag;

	struct AsBeginIterator{};

	ClockwiseBlockIterator() noexcept
		: last_node_id_{ 0u }
		, current_node_id_{ 0u }
		, map_graph_{ nullptr }
		, as_begin_{ false }
	{}

	ClockwiseBlockIterator(MapNode::ID prev_neighbor_node_id, 
		                   MapNode::ID start_node_id,
		                   const MapGraph& graph,
		                   AsBeginIterator) noexcept
		: last_node_id_{ prev_neighbor_node_id }
		, current_node_id_{ start_node_id }
		, map_graph_{&graph}
		, as_begin_{ true }
	{
		assert(map_graph_->map_node(start_node_id).neighbor_clockwise_of(prev_neighbor_node_id).has_value());
	}
	ClockwiseBlockIterator(MapNode::ID prev_neighbor_node_id,
		MapNode::ID start_node_id,
		const MapGraph& graph) noexcept
		: last_node_id_{ prev_neighbor_node_id }
		, current_node_id_{ start_node_id }
		, map_graph_{ &graph }
		, as_begin_{ false }
	{
		assert(map_graph_->map_node(start_node_id).neighbor_clockwise_of(prev_neighbor_node_id).has_value());
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
			// go back to base-of-spike node
			const MapNode::ID tmp = last_node_id_;
			last_node_id_ = current_node_id_;
			current_node_id_ = tmp;
			// and call increment again so that we don't have anyone call operator*() at this node again
			return ++(*this);
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

	const MapGraph& get_graph() const noexcept { return *map_graph_; }
	ClockwiseBlockIterator as_end() const noexcept {
		ClockwiseBlockIterator end_itr{ *this };
		end_itr.as_begin_ = false;
		return end_itr;
	}
};

// Range of all adjacencies in a block. Example usage:
//    for (const auto& adjacency : ClockwiseBlock{prev_id, start_id, graph}) {
//       // do something with edges
//    }
// Since a node be part of multiple blocks, the particular block is specified by
// passing the node ID *before* the start node (clockwise) and the starting node
// ID.
// Example: Imagine we want a block that includes node *5*.
//          In order to get the block {5,6,7,8,9,4}, we should
//          create a block iterator like ClockwiseBlockIterator{4,5,graph};
//          Conversely, to get the block {5,4,3,2,1,6} we should
//          create a block iterator like ClockwiseBlockIterator{6,5,graph};
//   
//   (3)------(2)------(1)
//    |                 |
//    |          <----  |
//   (4)------(5)------(6)
//    | ---->           |
//    |                 |
//   (9)------(8)------(7)
//
// Note: This algorithm will treat all nodes on the outer edge of a graph
//       connected component as a block. Steps must be taken to avoid that
//       case if this is not desirable.
class ClockwiseBlock {
	ClockwiseBlockIterator begin_;
	ClockwiseBlockIterator end_;
public:
	using iterator = ClockwiseBlockIterator;

	ClockwiseBlock()
		: begin_{}
		, end_{}
	{}
	ClockwiseBlock(MapNode::ID prev_neighbor, MapNode::ID starting_node, const MapGraph& graph)
		: begin_{ prev_neighbor, starting_node,  graph, iterator::AsBeginIterator{} }
		, end_{prev_neighbor, starting_node, graph }
	{}

	iterator begin() const { return begin_; }
	iterator end() const { return end_; }

	bool is_water_block() const {
		for (auto itr = begin_; itr != end_; ++itr) {
			const MapNode::ID node_id = *itr;
			const auto& graph = itr.get_graph();
			if (!graph.is_jack_node(node_id)) {
				continue;
			}
			const auto& j_node = graph.jack_node(node_id);
			if (j_node.is_water()) {
				return true;
			}
		}
		return false;
	}
};

} // namespace wl

#endif // WL_BLOCK_ITERATOR_H
