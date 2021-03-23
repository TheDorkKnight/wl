#include <array>
#include <unordered_map>
#include <gtest/gtest.h>
#include <wl/default_map.h>
#include <wl/node_blocks_iterator.h>
#include <wl/j_node_blocks_iterator.h>

namespace {
const wl::MapGraph default_map = wl::default_map();
} // namespace

namespace std {
template<>
struct hash<wl::MapNode::ID>
{
	std::size_t operator()(wl::MapNode::ID id_val) const noexcept {
		return std::hash<std::size_t>{}(static_cast<std::size_t>(id_val));
	}
};
} // namespace std

TEST(ClockwiseNodeBlocks, all_blocks_for_node_9) {
	const wl::ClockwiseNodeBlocks blocks_for_node_9{ wl::map_id(9u), default_map };
	

	auto itr = blocks_for_node_9.begin();
	const auto end = blocks_for_node_9.end();

	// expected topology:
	//     (001)---------      //   we expect to see the block: {9,189,1,190}
	//     /     vvv     \     //   and the block: {9,190,11,208,10,207,189}
	//--(189)---(009)---(190)--//
	//    \      ^^^       \   //
	//---(207)--(010)    (011) //
	//      \      `(208)-'    //
	//       \        \        //

	ASSERT_NE(end, itr);
	{
		const wl::ClockwiseBlock first_block = *itr;
		EXPECT_FALSE(first_block.is_water_block());
		constexpr std::array<wl::MapNode::Adjacency, 4> expected_adjacencies = {
			wl::map_id(9u), wl::map_id(189u), wl::map_id(1u), wl::map_id(190u)
		};
		EXPECT_TRUE(std::equal(
			first_block.begin(), first_block.end(),
			expected_adjacencies.begin(), expected_adjacencies.end()));
	}
	++itr;

	ASSERT_NE(end, itr);
	{
		const wl::ClockwiseBlock second_block = *itr;
		EXPECT_FALSE(second_block.is_water_block());
		constexpr std::array<wl::MapNode::Adjacency, 7> expected_adjacencies = {
			wl::map_id(9u),  wl::map_id(190u), wl::map_id(11u), wl::map_id(208u),
			wl::map_id(10u), wl::map_id(207u), wl::map_id(189u)
		};
		EXPECT_TRUE(std::equal(
			second_block.begin(), second_block.end(),
			expected_adjacencies.begin(), expected_adjacencies.end()));
	}
	++itr;

	EXPECT_EQ(end, itr);
}

TEST(JackNodeBlocks, all_blocks_for_node_9) {
	const wl::JackNodeBlocks blocks_for_node_9{ wl::map_id(9u), default_map };

	auto itr = blocks_for_node_9.begin();
	const auto end = blocks_for_node_9.end();

	// expected topology:
	//     (001)---------      //   since we are only looking at j nodes,
	//     /     vvv     \     //   we expect to see the block: {9,1}
	//--(189)---(009)---(190)--//   and the block: {9,11,10}
	//    \      ^^^       \   //
	//---(207)--(010)    (011) //
	//      \      `(208)-'    //
	//       \        \        //

	ASSERT_NE(end, itr);
	{
		const wl::JackNodesBlock first_block = *itr;
		EXPECT_FALSE(first_block.is_water_block());
		constexpr std::array<wl::MapNode::Adjacency, 2> expected_adjacencies = {
			wl::map_id(9u), wl::map_id(1u)
		};
		EXPECT_TRUE(std::equal(
			first_block.begin(), first_block.end(),
			expected_adjacencies.begin(), expected_adjacencies.end()));
	}
	++itr;

	ASSERT_NE(end, itr);
	{
		const wl::JackNodesBlock second_block = *itr;
		EXPECT_FALSE(second_block.is_water_block());
		constexpr std::array<wl::MapNode::Adjacency, 3> expected_adjacencies = {
			wl::map_id(9u), wl::map_id(11u), wl::map_id(10u)
		};
		EXPECT_TRUE(std::equal(
			second_block.begin(), second_block.end(),
			expected_adjacencies.begin(), expected_adjacencies.end()));
	}
	++itr;

	EXPECT_EQ(end, itr);
}

TEST(JackNodeBlocks, alley_neighbors_for_node_9) {
	const wl::JackNodeBlocks blocks_for_node_9{ wl::map_id(9u), default_map };

	std::unordered_map<wl::MapNode::ID, std::size_t> encountered_nodes;

	blocks_for_node_9.for_each_alley_neighbor(
		[&encountered_nodes](const wl::MapNode::ID id) {
			auto itr = encountered_nodes.find(id);
			if (itr == encountered_nodes.end()) {
				encountered_nodes.insert(std::make_pair(id, 1u));
			} else {
				++(itr->second);
			}
		});

	// expected topology:
	//     (001)---------      //   since we are only looking at j nodes,
	//     /     vvv     \     //   we expect to see neighbors {1,10,11}
	//--(189)---(009)---(190)--//
	//    \      ^^^       \   //
	//---(207)--(010)    (011) //
	//      \      `(208)-'    //
	//       \        \        //

	const auto find_1 = encountered_nodes.find(wl::map_id(1u));
	ASSERT_NE(encountered_nodes.end(), find_1);
	EXPECT_EQ(1u, find_1->second);

	const auto find_10 = encountered_nodes.find(wl::map_id(10u));
	ASSERT_NE(encountered_nodes.end(), find_10);
	EXPECT_EQ(1u, find_10->second);

	const auto find_11 = encountered_nodes.find(wl::map_id(11u));
	ASSERT_NE(encountered_nodes.end(), find_11);
	EXPECT_EQ(1u, find_11->second);

	EXPECT_EQ(3u, encountered_nodes.size());
}
