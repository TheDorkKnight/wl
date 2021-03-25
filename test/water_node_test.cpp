#include <gtest/gtest.h>
#include <wl/default_map.h>

namespace {
	const wl::MapGraph default_map = wl::default_map();
} // namespace

TEST(WaterNode, is_water) {
	constexpr wl::JackNode water_node{ wl::JackNode::Type::Water };
	static_assert(water_node.is_water());
	EXPECT_TRUE(water_node.is_water());
}
