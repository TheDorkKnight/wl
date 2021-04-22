#include <gtest/gtest.h>
#include <wl/jack_inventory.h>

TEST(JackInventory, default_values) {
	constexpr wl::JackInventory inventory;
	EXPECT_EQ(2u, inventory.num_carriages());
	EXPECT_EQ(2u, inventory.num_alleys());
	EXPECT_EQ(2u, inventory.num_boats());
}
