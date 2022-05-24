#ifndef WL_J_NODE_BLOCKS_ITERATOR_H
#define WL_J_NODE_BLOCKS_ITERATOR_H

#include <iterator>
#include <wl/wl.h>
#include <wl/node_blocks_iterator.h>
#include <wl/j_node_block_iterator.h>

namespace wl {

// Iterator over all blocks for a given map node. See ClockwiseNodeBlocks for usage.
class JackNodeBlocksIterator {
	ClockwiseNodeBlocksIterator itr_ = ClockwiseNodeBlocksIterator{};
	ClockwiseNodeBlocksIterator end_ = ClockwiseNodeBlocksIterator{};
	JackNodesBlock current_block_    = JackNodesBlock{};

public:
	using value_type = JackNodesBlock;
	using pointer = const JackNodesBlock*;
	using reference = value_type;
	using difference_type = std::ptrdiff_t;
	using iterator_category = std::input_iterator_tag;

	using AsEndIterator = typename ClockwiseNodeBlocksIterator::AsEndIterator;

	JackNodeBlocksIterator(MapNode::ID node_id,
		const MapGraph& graph) noexcept
		: itr_{ node_id, graph }
		, end_{ node_id, graph, AsEndIterator{} }
		, current_block_{}
	{
		if (itr_ != end_) {
			const ClockwiseBlock& underlying_block = *itr_;
			current_block_ = JackNodesBlock{ underlying_block.begin() };
		}
	}

	JackNodeBlocksIterator(MapNode::ID node_id,
		const MapGraph& graph,
		AsEndIterator) noexcept
		: itr_{ node_id, graph, AsEndIterator{} }
		, end_{ node_id, graph, AsEndIterator{} }
		, current_block_{}
	{}

	value_type operator*() const noexcept {
		return current_block_;
	}

	pointer operator->() const noexcept {
		return &current_block_;
	}

	JackNodeBlocksIterator& operator++() {
		++itr_;
		if (itr_ != end_) {
			const ClockwiseBlock& underlying_block = *itr_;
			current_block_ = JackNodesBlock{ underlying_block.begin() };
		} else {
			current_block_ = JackNodesBlock{};
		}
		return *this;
	}

	bool operator==(const JackNodeBlocksIterator& other) const noexcept {
		assert(end_ == other.end_);
		return itr_ == other.itr_;
	}
	bool operator!=(const JackNodeBlocksIterator& other) const noexcept {
		assert(end_ == other.end_);
		return itr_ != other.itr_;
	}
};

// Range of all jack nodes blocks for a given map node. Example usage:
//    for (const JackNodesBlock& jack_nodes_block : JackNodeBlocks{node_id, graph}) {
//       for (const auto& jack_node : jack_nodes_block) {
//          // do something with jack nodes
//       }
//    }
// Note: This algorithm will treat all nodes on the outer edge of a graph
//       connected component as a block. Steps must be taken to avoid that
//       case if this is not desirable.
class JackNodeBlocks {
	JackNodeBlocksIterator begin_;
	JackNodeBlocksIterator end_;
public:
	using iterator = JackNodeBlocksIterator;

	JackNodeBlocks(MapNode::ID node_id, const MapGraph& graph)
		: begin_{ node_id,  graph }
		, end_{ node_id, graph, iterator::AsEndIterator{} }
	{}

	iterator begin() const { return begin_; }
	iterator end() const { return end_; }

	// Use this function when the start node is a non-Water JackNode.
	template<class FuncOnAlleyNeighbors>
	void for_each_alley_neighbor(FuncOnAlleyNeighbors&& alley_func) const {
		for (auto itr = begin_; itr != end_; ++itr) {
			const JackNodesBlock& block = *itr;
			if (block.is_water_block()) {
				continue;
			}

			// move ahead by one, since each block starts with self
			auto block_itr = block.begin();
			const auto block_end = block.end();
			if (block_itr == block_end) {
				continue;
			}
			++block_itr;

			for (; block_itr != block_end; ++block_itr) {
				alley_func(*block_itr);
			}
		}
	}

	// Use this function when the start node is a Water JackNode. Any
	// block that a Water node touches is necessarily a water block, so
	// alleys do not apply.
	template<class FuncOnWaterNeighbors>
	void for_each_water_neighbor(FuncOnWaterNeighbors&& water_func) const {
		for (auto itr = begin_; itr != end_; ++itr) {
			const JackNodesBlock& block = *itr;
			if (!block.is_water_block()) {
				continue;
			}

			// move ahead by one, since each block starts with self
			auto block_itr = block.begin();
			const auto block_end = block.end();
			if (block_itr == block_end) {
				continue;
			}
			assert(block_itr.get_graph().jack_node(*block_itr).is_water());
			++block_itr;

			for (; block_itr != block_end; ++block_itr) {
				const auto id = *block_itr;
				const auto& jack_node = block_itr.get_graph().jack_node(id);
				if (!jack_node.is_water()) {
					continue;
				}
				water_func(id);
			}
		}
	}
};

} // namespace wl

#endif // WL_J_NODE_BLOCKS_ITERATOR_H

