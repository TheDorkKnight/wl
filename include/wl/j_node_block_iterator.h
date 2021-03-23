#ifndef WL_J_NODE_BLOCK_ITERATOR_H
#define WL_J_NODE_BLOCK_ITERATOR_H

#include <iterator>
#include <wl/wl.h>
#include <wl/block_iterator.h>

namespace wl {

// Iterator over all adjacencies in a particular block. See ClockwiseBlock for usage.
class JackNodeBlockIterator {
	ClockwiseBlockIterator itr_{};
	ClockwiseBlockIterator end_{};

public:
	using value_type = typename ClockwiseBlockIterator::value_type;
	using pointer = typename ClockwiseBlockIterator::pointer;
	using reference = typename ClockwiseBlockIterator::reference;
	using difference_type = typename ClockwiseBlockIterator::difference_type;
	using iterator_category = typename ClockwiseBlockIterator::iterator_category;

	using AsBeginIterator = typename ClockwiseBlockIterator::AsBeginIterator;

	JackNodeBlockIterator() noexcept
		: itr_{}
		, end_{}
	{}

	JackNodeBlockIterator(MapNode::ID prev_neighbor_node_id,
		MapNode::ID start_node_id,
		const MapGraph& graph,
		AsBeginIterator as_begin) noexcept
		: itr_{ prev_neighbor_node_id, start_node_id, graph, as_begin }
		, end_{ prev_neighbor_node_id, start_node_id, graph }
	{
		while ((itr_ != end_) && (!graph.is_jack_node(*itr_))) {
			++itr_;
		}
	}
	JackNodeBlockIterator(MapNode::ID prev_neighbor_node_id,
		MapNode::ID start_node_id,
		const MapGraph& graph) noexcept
		: itr_{ prev_neighbor_node_id, start_node_id, graph }
		, end_{ itr_ }
	{
	}

	value_type operator*() const noexcept {
		return *itr_;
	}

	pointer operator->() const noexcept {
		return itr_.operator->();
	}

	JackNodeBlockIterator& operator++() {
		++itr_;
		while ((itr_ != end_) && (!itr_.get_graph().is_jack_node(*itr_))) {
			++itr_;
		}
		return *this;
	}

	bool operator==(const JackNodeBlockIterator& other) const noexcept {
		assert(end_ == other.end_);
		return itr_ == other.itr_;
	}
	bool operator!=(const JackNodeBlockIterator& other) const noexcept {
		assert(end_ == other.end_);
		return itr_ != other.itr_;
	}

	const MapGraph& get_graph() const noexcept { return itr_.get_graph(); }
	const ClockwiseBlockIterator& get_end() const noexcept { return end_; }
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
class JackNodesBlock {
	JackNodeBlockIterator begin_;
	JackNodeBlockIterator end_;
public:
	using iterator = JackNodeBlockIterator;

	JackNodesBlock()
		: begin_{}
		, end_{}
	{}
	JackNodesBlock(MapNode::ID prev_neighbor, MapNode::ID starting_node, const MapGraph& graph)
		: begin_{ prev_neighbor, starting_node,  graph, iterator::AsBeginIterator{} }
		, end_{ prev_neighbor, starting_node, graph }
	{}

	iterator begin() const { return begin_; }
	iterator end() const { return end_; }

	bool is_water_block() const {
		for (auto itr = begin_; itr != end_; ++itr) {
			const MapNode::ID node_id = *itr;
			const auto& graph = itr.get_graph();
			const auto& j_node = graph.jack_node(node_id);
			if (j_node.is_water()) {
				return true;
			}
		}
		return false;
	}
};

} // namespace wl

#endif // WL_J_NODE_BLOCK_ITERATOR_H

