#include <array>
#include <gtest/gtest.h>
#include <wl/default_map.h>
#include <wl/node_blocks_iterator.h>

namespace {
	const wl::MapGraph default_map = wl::default_map();
} // namespace

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
