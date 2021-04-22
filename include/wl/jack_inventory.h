#ifndef WL_JACK_INVENTORY_H
#define WL_JACK_INVENTORY_H

#include <cstdint>
#include <cassert>

namespace wl {

class JackInventory {
	std::uint8_t num_carriages_ = 2u;
	std::uint8_t num_alleys_    = 2u;
	std::uint8_t num_boats_     = 2u;

public:
	constexpr JackInventory() noexcept = default;

	constexpr JackInventory(std::uint8_t num_cs,
		                    std::uint8_t num_as,
		                    std::uint8_t num_bs) noexcept
		: num_carriages_{num_cs}
		, num_alleys_{num_as}
		, num_boats_{num_bs}
	{}

	constexpr std::uint8_t num_carriages() const noexcept { return num_carriages_; }
	constexpr std::uint8_t num_alleys() const noexcept { return num_alleys_; }
	constexpr std::uint8_t num_boats() const noexcept { return num_boats_; }

	// REQUIRED: num_carriages() > 0
	void use_carriage() noexcept {
		assert(num_carriages_ > 0u);
		num_carriages_ -= 1u;
	}

	// REQUIRED: num_alleys() > 0
	void use_alley() noexcept {
		assert(num_alleys_ > 0u);
		num_alleys_ -= 1u;
	}

	// REQUIRED: num_boats() > 0
    void use_boat() noexcept {
		assert(num_boats_ > 0u);
		num_boats_ -= 1u;
	}
};

} // namespace

#endif
