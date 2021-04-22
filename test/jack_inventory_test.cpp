#include <gtest/gtest.h>
#include <wl/jack_inventory.h>

TEST(JackInventory, default_values) {
	constexpr wl::JackInventory inventory;
	EXPECT_EQ(2u, inventory.num_carriages());
	EXPECT_EQ(2u, inventory.num_alleys());
	EXPECT_EQ(2u, inventory.num_boats());
}

TEST(JackInventory, can_decrement_values) {
	wl::JackInventory inventory;
	{
		const auto original_num_carriages = inventory.num_carriages();
		ASSERT_NE(0u, original_num_carriages);

		inventory.use_carriage();
		EXPECT_EQ(original_num_carriages - 1u, inventory.num_carriages());
	}
	{
		const auto original_num_alleys = inventory.num_alleys();
		ASSERT_NE(0u, original_num_alleys);

		inventory.use_alley();
		EXPECT_EQ(original_num_alleys - 1u, inventory.num_alleys());
	}
	{
		const auto original_num_boats = inventory.num_boats();
		ASSERT_NE(0u, original_num_boats);

		inventory.use_boat();
		EXPECT_EQ(original_num_boats - 1u, inventory.num_boats());
	}
}
