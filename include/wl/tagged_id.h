#ifndef WL_TAGGED_ID_H
#define WL_TAGGED_ID_H

#include <cstdint>

namespace wl {

template<class IDTag>
class TaggedID {
	std::uint8_t id_ = 0u;
public:
	explicit constexpr TaggedID(std::uint8_t id_val) noexcept
		: id_{id_val}
	{}

	explicit constexpr operator std::uint8_t() const noexcept {
		return id_;
	}
	explicit constexpr operator int() const noexcept {
		return static_cast<int>(id_);
	}

	constexpr TaggedID& operator++() noexcept {
		++id_;
		return *this;
	}
	constexpr TaggedID operator++(int) noexcept {
		TaggedID tmp{*this};
		++id_;
		return tmp;
	}
	constexpr TaggedID& operator--() noexcept {
		--id_;
		return *this;
	}
	constexpr TaggedID operator--(int) noexcept {
		TaggedID tmp{*this};
		--id_;
		return tmp;
	}

	constexpr bool operator==(const TaggedID& other) const noexcept {
		return id_ == other.id_;
	}
	constexpr bool operator!=(const TaggedID& other) const noexcept {
		return id_ != other.id_;
	}
	constexpr bool operator<(const TaggedID& other) const noexcept {
		return id_ < other.id_;
	}
	constexpr bool operator<=(const TaggedID& other) const noexcept {
		return id_ <= other.id_;
	}
	constexpr bool operator>(const TaggedID& other) const noexcept {
		return id_ > other.id_;
	}
	constexpr bool operator>=(const TaggedID& other) const noexcept {
		return id_ >= other.id_;
	}
};

} // namespace wl

#endif
