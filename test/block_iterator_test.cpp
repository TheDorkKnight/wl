#include <gtest/gtest.h>
#include <wl/default_map.h>
#include <wl/block_iterator.h>
#include <wl/j_node_block_iterator.h>

namespace {
const wl::MapGraph default_map = wl::default_map();
} // namespace

TEST(ClockwiseBlockIterator, iterate_around_first_block) {
	const wl::ClockwiseBlock first_block{ wl::map_id(189u), wl::map_id(1u), default_map };
	EXPECT_FALSE(first_block.is_water_block());

	auto itr = first_block.begin();
	const auto end = first_block.end();

	// expected topology:
	//     (001)---------     //
	//     /             \    //
	//  (189)---(009)---(190) //
	
	ASSERT_NE(end, itr);
	EXPECT_EQ(wl::map_id(1u), *itr);

	++itr;
	ASSERT_NE(end, itr);
	EXPECT_EQ(wl::map_id(190u), *itr);

	++itr;
	ASSERT_NE(end, itr);
	EXPECT_EQ(wl::map_id(9u), *itr);

	++itr;
	ASSERT_NE(end, itr);
	EXPECT_EQ(wl::map_id(189u), *itr);

	++itr;
	EXPECT_EQ(end, itr);
}

TEST(JackNodesBlockIterator, iterate_around_first_block) {
	const wl::JackNodesBlock first_block{ wl::map_id(189u), wl::map_id(1u), default_map };
	EXPECT_FALSE(first_block.is_water_block());

	auto itr = first_block.begin();
	const auto end = first_block.end();

	// expected topology:
	//     (001)---------     //  1 and 9 are Jack nodes
	//     /             \    //
	//  (189)---(009)---(190) //

	ASSERT_NE(end, itr);
	EXPECT_EQ(wl::map_id(1u), *itr);

	++itr;
	ASSERT_NE(end, itr);
	EXPECT_EQ(wl::map_id(9u), *itr);

	++itr;
	EXPECT_EQ(end, itr);
}
