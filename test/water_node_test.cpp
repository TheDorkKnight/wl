#include <gtest/gtest.h>
#include <wl/wl.h>

TEST(WaterNode, can_drop_evidence) {
	constexpr wl::JackNode water_node{ wl::JackNode::Type::Water };
	static_assert(!water_node.can_drop_evidence());
	EXPECT_FALSE(water_node.can_drop_evidence());
}

TEST(WaterNode, is_water) {
	constexpr wl::JackNode water_node{ wl::JackNode::Type::Water };
	static_assert(water_node.is_water());
	EXPECT_TRUE(water_node.is_water());
}
