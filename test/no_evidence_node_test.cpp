#include <gtest/gtest.h>
#include <wl/wl.h>

TEST(NoEvidenceNode, can_drop_evidence) {
	constexpr wl::JackNode no_evidence_node{ wl::JackNode::Type::NoEvidence };
	static_assert(!no_evidence_node.can_drop_evidence());
	EXPECT_FALSE(no_evidence_node.can_drop_evidence());
}

TEST(NoEvidenceNode, is_not_water) {
	constexpr wl::JackNode no_evidence_node{ wl::JackNode::Type::NoEvidence };
	static_assert(!no_evidence_node.is_water());
	EXPECT_FALSE(no_evidence_node.is_water());
}
