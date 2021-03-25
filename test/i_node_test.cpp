#include <gtest/gtest.h>
#include <wl/wl.h>

TEST(InvestigatorNode, not_starting_position_by_default) {
	constexpr wl::InvestigatorNode default_i_node;
	static_assert(!default_i_node.is_starting_position());
	EXPECT_FALSE(default_i_node.is_starting_position());
}

TEST(InvestigatorNode, is_starting_position_when_tagged) {
	constexpr wl::InvestigatorNode starting_i_node{ wl::InvestigatorNode::StartPosition{} };
	static_assert(starting_i_node.is_starting_position());
	EXPECT_TRUE(starting_i_node.is_starting_position());
}
