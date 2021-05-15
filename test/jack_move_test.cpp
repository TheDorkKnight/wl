#include <gtest/gtest.h>
#include <wl/j_moves.h>

TEST(JackMove, no_cost) {
	const wl::JackMove move{ wl::map_id(2) };

	const auto cost = move.cost();
	EXPECT_EQ(cost, std::nullopt);
}

TEST(JackMove, accurate_cost) {
	const wl::JackMove move{ wl::map_id(2), wl::JackResource::CARRIAGE };

	const auto cost = move.cost();
	ASSERT_TRUE(cost.has_value());
	EXPECT_EQ(cost, wl::JackResource::CARRIAGE);
}

TEST(JackMove, accurate_destination) {
	const wl::JackMove move{ wl::map_id(2) };
	const wl::JackMove move_with_cost{ wl::map_id(3), wl::JackResource::CARRIAGE };

	const auto destination = move.destination();
	const auto destination_with_cost = move_with_cost.destination();
	EXPECT_EQ(destination, wl::map_id(2) );
	EXPECT_EQ(destination_with_cost, wl::map_id(3));
}
