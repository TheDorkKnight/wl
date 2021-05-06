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

TEST(JackInventory, specific_values) {
	constexpr wl::JackInventory inventory{0u, 1u, 255u};
	EXPECT_EQ(0u, inventory.num_carriages());
	EXPECT_EQ(1u, inventory.num_alleys());
	EXPECT_EQ(255u, inventory.num_boats());
}

TEST(JackInventory, num_of) {
	constexpr wl::JackInventory inventory{ 0u, 1u, 255u };
	EXPECT_EQ(0u, inventory.num_of(wl::JackResource::CARRIAGE));
	EXPECT_EQ(1u, inventory.num_of(wl::JackResource::ALLEY));
	EXPECT_EQ(255u, inventory.num_of(wl::JackResource::BOAT));
}

static void use_jack_resource(wl::JackInventory& inventory, wl::JackResource resource) {
	const auto original_num = inventory.num_of(resource);
	ASSERT_NE(0u, original_num);

	inventory.use(resource);
	EXPECT_EQ(original_num - 1u, inventory.num_of(resource));
}

TEST(JackInventory, use_jackresource) {
	wl::JackInventory inventory;
		
	use_jack_resource(inventory, wl::JackResource::CARRIAGE);

	use_jack_resource(inventory, wl::JackResource::ALLEY);

	use_jack_resource(inventory, wl::JackResource::BOAT);
}
