#ifndef WL_TAGGED_ID_H
#define WL_TAGGED_ID_H

#include <cstdint>
#include <type_traits>

namespace wl {

template<class IDTag, class NumberType = std::uint8_t>
class TaggedID {
	static_assert(std::is_unsigned_v<NumberType>);
	NumberType id_ = 0u;
public:
	explicit constexpr TaggedID(NumberType id_val) noexcept
		: id_{id_val}
	{}

	explicit constexpr operator NumberType() const noexcept {
		return id_;
	}
	explicit constexpr operator std::size_t() const noexcept {
		return static_cast<std::size_t>(id_);
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
