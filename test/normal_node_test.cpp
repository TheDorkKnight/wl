#include <gtest/gtest.h>
#include <wl/wl.h>

TEST(NormalNode, can_drop_evidence) {
	constexpr wl::JackNode normal_node{ wl::JackNode::Type::Normal };
	static_assert(normal_node.can_drop_evidence());
	EXPECT_TRUE(normal_node.can_drop_evidence());
}

TEST(NormalNode, is_not_water) {
	constexpr wl::JackNode normal_node{ wl::JackNode::Type::Normal };
	static_assert(!normal_node.is_water());
	EXPECT_FALSE(normal_node.is_water());
}

TEST(NormalNode, can_drop_evidence_by_default) {
	constexpr wl::JackNode default_node{};
	static_assert(default_node.can_drop_evidence());
	EXPECT_TRUE(default_node.can_drop_evidence());
}

TEST(NormalNode, is_not_water_by_default) {
	constexpr wl::JackNode default_node{};
	static_assert(!default_node.is_water());
	EXPECT_FALSE(default_node.is_water());
}
