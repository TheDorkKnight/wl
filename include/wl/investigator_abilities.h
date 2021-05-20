#ifndef WL_INVESTIGATOR_ABILITIES_H
#define WL_INVESTIGATOR_ABILITIES_H

#include <cassert>
#include <array>
#include <wl/investigator_id.h>

namespace wl {

class InvestigatorAbilities {
	std::array<bool,3> main_ability_available_ = {true, true, true};
	bool smoker_available_ = true;

public:
	struct WithoutSmoker{};

	constexpr InvestigatorAbilities() noexcept
		: main_ability_available_{true, true, true}
		, smoker_available_{true}
	{}

	constexpr InvestigatorAbilities(WithoutSmoker) noexcept
		: main_ability_available_{true, true, true}
		, smoker_available_{false}
	{}

	constexpr bool ability_available(InvestigatorID id) const noexcept {
		switch (id) {
		case InvestigatorID::ZERO: return std::get<0>(main_ability_available_);
		case InvestigatorID::ONE:  return std::get<1>(main_ability_available_);
		case InvestigatorID::TWO:  break;
		}
		return std::get<2>(main_ability_available_);
	}
	constexpr bool smoker_available() const noexcept {
		return smoker_available_;
	}

	void use_ability(InvestigatorID id) noexcept {
		assert(ability_available(id));
		switch (id) {
		case InvestigatorID::ZERO: std::get<0>(main_ability_available_) = false; break;
		case InvestigatorID::ONE:  std::get<1>(main_ability_available_) = false; break;
		case InvestigatorID::TWO:  std::get<2>(main_ability_available_) = false; break;
		}
	}
	void use_smoker() noexcept {
		assert(smoker_available_);
		smoker_available_ = false;
	}
};

} // namespace wl

#endif
