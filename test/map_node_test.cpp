#include <gtest/gtest.h>
#include <wl/default_map.h>

namespace {
const wl::MapGraph default_map = wl::default_map();
} // namespace

TEST(MapNode, neighbor_clockwise) {
	// Node 2 should have three neighbors: 192, 193, and 194
	// which are in clockwise order. Let's make sure we can
	// go clockwise in-between them.
	const auto& node_2 = default_map.map_node(wl::map_id(2));

	// now, we don't actually care which is the first one
	// (we only care that they are in clockwise order), so
	// set up our expectations with a function:
	const auto expected_after = [] (wl::MapNode::ID id) -> std::optional<wl::MapNode::ID> {
		constexpr wl::MapNode::ID k_192{wl::map_id(192u)};
		constexpr wl::MapNode::ID k_193{wl::map_id(193u)};
		constexpr wl::MapNode::ID k_194{wl::map_id(194u)};
		if (id == k_192) {
			return k_193;
		} else if (id == k_193) {
			return k_194;
		} else if (id == k_194) {
			return k_192;
		}
		return std::nullopt;
	};

	EXPECT_EQ(3u, node_2.neighbors().size());
	for (const wl::MapNode::ID nbor_id : node_2.neighbors()) {
		const auto expected_clockwise_nbor = expected_after(nbor_id);
		if (!expected_clockwise_nbor.has_value()) {
			FAIL() << "got unexpected neighbor " << static_cast<std::size_t>(nbor_id);
			continue;
		}
		const auto actual_clockwise_nbor = node_2.neighbor_clockwise_of(nbor_id);
		if (!actual_clockwise_nbor.has_value()) {
			FAIL() << "neighbor " << static_cast<std::size_t>(nbor_id) << " had no clockwise neighbor";
			continue;
		}
		EXPECT_EQ(*expected_clockwise_nbor, *actual_clockwise_nbor);
	}

	// test that a node which is not actually a neighbor of node 2
	// has no clockwise neighbor
	const auto clockwise_of_1 = node_2.neighbor_clockwise_of(wl::map_id(1u));
	EXPECT_FALSE(clockwise_of_1.has_value());
}

TEST(MapNode, neighbor_counter_clockwise) {
	// Node 2 should have three neighbors: 192, 193, and 194
	// which are in clockwise order. Let's make sure we can
	// go counter-clockwise in-between them.
	const auto& node_2 = default_map.map_node(wl::map_id(2));

	// now, we don't actually care which is the first one
	// (we only care that they are in counter-clockwise order),
	// so set up our expectations with a function:
	const auto expected_after = [] (wl::MapNode::ID id) -> std::optional<wl::MapNode::ID> {
		constexpr wl::MapNode::ID k_192{wl::map_id(192u)};
		constexpr wl::MapNode::ID k_193{wl::map_id(193u)};
		constexpr wl::MapNode::ID k_194{wl::map_id(194u)};
		if (id == k_192) {
			return k_194;
		} else if (id == k_193) {
			return k_192;
		} else if (id == k_194) {
			return k_193;
		}
		return std::nullopt;
	};

	EXPECT_EQ(3u, node_2.neighbors().size());
	for (const wl::MapNode::ID nbor_id : node_2.neighbors()) {
		const auto expected_counter_clockwise_nbor = expected_after(nbor_id);
		if (!expected_counter_clockwise_nbor.has_value()) {
			FAIL() << "got unexpected neighbor " << static_cast<std::size_t>(nbor_id);
			continue;
		}
		const auto actual_counter_clockwise_nbor = node_2.neighbor_counter_clockwise_of(nbor_id);
		if (!actual_counter_clockwise_nbor.has_value()) {
			FAIL() << "neighbor " << static_cast<std::size_t>(nbor_id) << " had no counter-clockwise neighbor";
			continue;
		}
		EXPECT_EQ(*expected_counter_clockwise_nbor, *actual_counter_clockwise_nbor);
	}

	// test that a node which is not actually a neighbor of node 2
	// has no counter-clockwise neighbor
	const auto clockwise_of_3 = node_2.neighbor_clockwise_of(wl::map_id(3u));
	EXPECT_FALSE(clockwise_of_3.has_value());
}
