#include <gtest/gtest.h>
#include <wl/investigator_abilities.h>

TEST(InvestigatorAbilities, default_initialization) {
	constexpr wl::InvestigatorAbilities abilities{};
	EXPECT_TRUE(abilities.ability_available(wl::InvestigatorID::ZERO));
	EXPECT_TRUE(abilities.ability_available(wl::InvestigatorID::ONE));
	EXPECT_TRUE(abilities.ability_available(wl::InvestigatorID::TWO));
	EXPECT_TRUE(abilities.smoker_available());
}

TEST(InvestigatorAbilities, without_smoker_initialization) {
	constexpr wl::InvestigatorAbilities abilities{
		wl::InvestigatorAbilities::WithoutSmoker{}};
	EXPECT_TRUE(abilities.ability_available(wl::InvestigatorID::ZERO));
	EXPECT_TRUE(abilities.ability_available(wl::InvestigatorID::ONE));
	EXPECT_TRUE(abilities.ability_available(wl::InvestigatorID::TWO));
	EXPECT_FALSE(abilities.smoker_available());
}

TEST(InvestigatorAbilities, can_use_abilities) {
	wl::InvestigatorAbilities abilities;

	abilities.use_ability(wl::InvestigatorID::ZERO);
	EXPECT_FALSE(abilities.ability_available(wl::InvestigatorID::ZERO));
	EXPECT_TRUE(abilities.ability_available(wl::InvestigatorID::ONE));
	EXPECT_TRUE(abilities.ability_available(wl::InvestigatorID::TWO));
	EXPECT_TRUE(abilities.smoker_available());

	abilities.use_ability(wl::InvestigatorID::ONE);
	EXPECT_FALSE(abilities.ability_available(wl::InvestigatorID::ZERO));
	EXPECT_FALSE(abilities.ability_available(wl::InvestigatorID::ONE));
	EXPECT_TRUE(abilities.ability_available(wl::InvestigatorID::TWO));
	EXPECT_TRUE(abilities.smoker_available());

	abilities.use_ability(wl::InvestigatorID::TWO);
	EXPECT_FALSE(abilities.ability_available(wl::InvestigatorID::ZERO));
	EXPECT_FALSE(abilities.ability_available(wl::InvestigatorID::ONE));
	EXPECT_FALSE(abilities.ability_available(wl::InvestigatorID::TWO));
	EXPECT_TRUE(abilities.smoker_available());

	abilities.use_smoker();
	EXPECT_FALSE(abilities.ability_available(wl::InvestigatorID::ZERO));
	EXPECT_FALSE(abilities.ability_available(wl::InvestigatorID::ONE));
	EXPECT_FALSE(abilities.ability_available(wl::InvestigatorID::TWO));
	EXPECT_FALSE(abilities.smoker_available());
}
