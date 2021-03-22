#include <gtest/gtest.h>
#include <wl/default_map.h>

namespace {
	const wl::MapGraph default_map = wl::default_map();
} // namespace

TEST(WaterNode, has_no_water_border_by_default) {
	constexpr wl::JackNode::Water default_water;
	static_assert(!default_water.water_border_neighbor().has_value());

	const auto water_border_neighbor = default_water.water_border_neighbor();
	EXPECT_FALSE(water_border_neighbor.has_value());
}

TEST(WaterNode, sixty_six_to_ninety_eight_water_border) {
	constexpr auto k_66 = wl::map_id(66u);
	constexpr auto k_98 = wl::map_id(98u);

	{
		const auto& jnode_66 = default_map.jack_node(k_66);
		const auto jnode_66_water_neighbor = jnode_66.water_border_neighbor();
		ASSERT_TRUE(jnode_66_water_neighbor.has_value());
		EXPECT_EQ(k_98, *jnode_66_water_neighbor);
	}

	{
		const auto& jnode_98 = default_map.jack_node(k_98);
		const auto jnode_98_water_neighbor = jnode_98.water_border_neighbor();
		ASSERT_TRUE(jnode_98_water_neighbor.has_value());
		EXPECT_EQ(k_66, *jnode_98_water_neighbor);
	}
}
