#ifndef WL_NODE_BLOCKS_ITERATOR_H
#define WL_NODE_BLOCKS_ITERATOR_H

#include <iterator>
#include <wl/wl.h>
#include <wl/block_iterator.h>

namespace wl {

// Iterator over all blocks for a given map node. See ClockwiseNodeBlocks for usage.
class ClockwiseNodeBlocksIterator {
	MapNode::ID node_id_                                     = MapNode::ID{ 0u };
	std::span<const MapNode::Adjacency> remaining_neighbors_ = std::span<const MapNode::Adjacency>{};
	const MapGraph* map_graph_                               = nullptr;
	ClockwiseBlock current_block_                            = ClockwiseBlock{};

public:
	using value_type = ClockwiseBlock;
	using pointer = const ClockwiseBlock*;
	using reference = value_type;
	using difference_type = std::ptrdiff_t;
	using iterator_category = std::input_iterator_tag;

	struct AsEndIterator{};

	ClockwiseNodeBlocksIterator()
		: node_id_{0u}
		, remaining_neighbors_{}
		, map_graph_{nullptr}
		, current_block_{}
	{}

	ClockwiseNodeBlocksIterator(MapNode::ID node_id,
		const MapGraph& graph) noexcept
		: node_id_{ node_id }
		, remaining_neighbors_{}
		, map_graph_{ &graph }
		, current_block_{}
	{
		const auto& start_node = graph.map_node(node_id);
		remaining_neighbors_ = start_node.neighbors();
		if (!remaining_neighbors_.empty()) {
			current_block_ = ClockwiseBlock{
				start_node.neighbor_counter_clockwise_of(remaining_neighbors_.front().id())->id(),
				node_id,
				*map_graph_};
		}
	}

	ClockwiseNodeBlocksIterator(MapNode::ID node_id,
		const MapGraph& graph,
		AsEndIterator) noexcept
		: node_id_{ node_id }
		, remaining_neighbors_{}
		, map_graph_{ &graph }
		, current_block_{}
	{}

	value_type operator*() const noexcept {
		return current_block_;
	}

	pointer operator->() const noexcept {
		return &current_block_;
	}

	ClockwiseNodeBlocksIterator& operator++() {
		remaining_neighbors_ = remaining_neighbors_.subspan(1u);
		if (remaining_neighbors_.empty()) {
			current_block_ = ClockwiseBlock{};
		} else {
			const auto& start_node = map_graph_->map_node(node_id_);
			current_block_ = ClockwiseBlock{
				start_node.neighbor_counter_clockwise_of(remaining_neighbors_.front().id())->id(),
				node_id_,
				*map_graph_ };
		}
		return *this;
	}

	bool operator==(const ClockwiseNodeBlocksIterator& other) const noexcept {
		assert(map_graph_ == other.map_graph_);
		assert(node_id_ == other.node_id_);
		return spans_equivalent(remaining_neighbors_, other.remaining_neighbors_);
	}
	bool operator!=(const ClockwiseNodeBlocksIterator& other) const noexcept {
		assert(map_graph_ == other.map_graph_);
		assert(node_id_ == other.node_id_);
		return !spans_equivalent(remaining_neighbors_, other.remaining_neighbors_);
	}

private:
	static bool spans_equivalent(std::span<const MapNode::Adjacency> a, std::span<const MapNode::Adjacency> b) noexcept {
		if (a.empty()) {
			return b.empty();
		}
		return (a.begin() == b.begin()) && (a.end() == b.end());
	}
};

// Range of all blocks for a given map node. Example usage:
//    for (const auto& block : ClockwiseNodeBlocks{node_id, graph}) {
//       for (const auto& adjacency : block) {
//          // do something with edges
//       }
//    }
// Note: This algorithm will treat all nodes on the outer edge of a graph
//       connected component as a block. Steps must be taken to avoid that
//       case if this is not desirable.
class ClockwiseNodeBlocks {
	ClockwiseNodeBlocksIterator begin_{};
	ClockwiseNodeBlocksIterator end_{};
public:
	using iterator = ClockwiseNodeBlocksIterator;

	ClockwiseNodeBlocks(MapNode::ID node_id, const MapGraph& graph)
		: begin_{ node_id,  graph }
		, end_{ node_id, graph, iterator::AsEndIterator{} }
	{}

	iterator begin() const { return begin_; }
	iterator end() const { return end_; }
};

} // namespace wl

#endif // WL_NODE_BLOCKS_ITERATOR_H

