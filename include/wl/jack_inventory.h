#ifndef WL_JACK_INVENTORY_H
#define WL_JACK_INVENTORY_H

#include <cstdint>
#include <cassert>
#include <exception>

namespace wl {

enum class JackResource {
	CARRIAGE,
	ALLEY,
	BOAT
};

class JackInventory {
	std::uint8_t num_carriages_ = 2u;
	std::uint8_t num_alleys_    = 2u;
	std::uint8_t num_boats_     = 2u;

public:
	constexpr JackInventory() noexcept = default;

	constexpr JackInventory(std::uint8_t num_crgs,
		                    std::uint8_t num_alys,
		                    std::uint8_t num_bts) noexcept
		: num_carriages_{num_crgs}
		, num_alleys_{num_alys}
		, num_boats_{num_bts}
	{}

	constexpr std::uint8_t num_carriages() const noexcept { return num_carriages_; }
	constexpr std::uint8_t num_alleys() const noexcept { return num_alleys_; }
	constexpr std::uint8_t num_boats() const noexcept { return num_boats_; }
	constexpr std::uint8_t num_of(JackResource resource) const noexcept { 
		switch (resource) {
		case JackResource::CARRIAGE: return num_carriages_;
		case JackResource::ALLEY: return num_alleys_;
		case JackResource::BOAT: return num_boats_;
		}
		std::terminate();
	}

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

	void use(JackResource resource) noexcept {
		switch (resource) {
		case JackResource::CARRIAGE: use_carriage(); break;
		case JackResource::ALLEY: use_alley(); break;
		case JackResource::BOAT: use_boat(); break;
		}
	}

};

} // namespace

#endif
