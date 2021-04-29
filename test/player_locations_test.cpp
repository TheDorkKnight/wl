#include <gtest/gtest.h>
#include <wl/player_locations.h>

TEST(PlayerLocations, initialization_and_accessors) {
	constexpr auto iloc_0 = wl::map_id(190u);
	constexpr auto iloc_1 = wl::map_id(191u);
	constexpr auto iloc_2 = wl::map_id(192u);
	constexpr auto jloc   = wl::map_id(1u);
	constexpr wl::PlayerLocations locations{iloc_0, iloc_1, iloc_2, jloc};
	EXPECT_EQ(iloc_0, locations.investigator_location(wl::InvestigatorID::ZERO));
	EXPECT_EQ(iloc_1, locations.investigator_location(wl::InvestigatorID::ONE));
	EXPECT_EQ(iloc_2, locations.investigator_location(wl::InvestigatorID::TWO));
	EXPECT_EQ(jloc, locations.jack_location());
}

TEST(PlayerLocations, can_move_players) {
	constexpr auto iloc_0_0 = wl::map_id(190u);
	constexpr auto iloc_1_0 = wl::map_id(191u);
	constexpr auto iloc_2_0 = wl::map_id(192u);
	constexpr auto jloc_0   = wl::map_id(1u);
	wl::PlayerLocations locations{iloc_0_0, iloc_1_0, iloc_2_0, jloc_0};

	constexpr auto iloc_0_1 = wl::map_id(200u);
	constexpr auto iloc_1_1 = wl::map_id(201u);
	constexpr auto iloc_2_1 = wl::map_id(202u);
	constexpr auto jloc_1   = wl::map_id(2u);

	locations.move_investigator(wl::InvestigatorID::ZERO, iloc_0_1);
	EXPECT_EQ(iloc_0_1, locations.investigator_location(wl::InvestigatorID::ZERO));
	EXPECT_EQ(iloc_1_0, locations.investigator_location(wl::InvestigatorID::ONE));
	EXPECT_EQ(iloc_2_0, locations.investigator_location(wl::InvestigatorID::TWO));
	EXPECT_EQ(jloc_0, locations.jack_location());

	locations.move_investigator(wl::InvestigatorID::ONE, iloc_1_1);
	EXPECT_EQ(iloc_0_1, locations.investigator_location(wl::InvestigatorID::ZERO));
	EXPECT_EQ(iloc_1_1, locations.investigator_location(wl::InvestigatorID::ONE));
	EXPECT_EQ(iloc_2_0, locations.investigator_location(wl::InvestigatorID::TWO));
	EXPECT_EQ(jloc_0, locations.jack_location());

	locations.move_investigator(wl::InvestigatorID::TWO, iloc_2_1);
	EXPECT_EQ(iloc_0_1, locations.investigator_location(wl::InvestigatorID::ZERO));
	EXPECT_EQ(iloc_1_1, locations.investigator_location(wl::InvestigatorID::ONE));
	EXPECT_EQ(iloc_2_1, locations.investigator_location(wl::InvestigatorID::TWO));
	EXPECT_EQ(jloc_0, locations.jack_location());

	locations.move_jack(jloc_1);
	EXPECT_EQ(iloc_0_1, locations.investigator_location(wl::InvestigatorID::ZERO));
	EXPECT_EQ(iloc_1_1, locations.investigator_location(wl::InvestigatorID::ONE));
	EXPECT_EQ(iloc_2_1, locations.investigator_location(wl::InvestigatorID::TWO));
	EXPECT_EQ(jloc_1, locations.jack_location());
}
