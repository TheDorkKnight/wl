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
	for (const wl::MapNode::Adjacency nbor_adjacency : node_2.neighbors()) {
		const auto expected_clockwise_nbor_id = expected_after(nbor_adjacency.id());
		if (!expected_clockwise_nbor_id.has_value()) {
			FAIL() << "got unexpected neighbor " << static_cast<std::size_t>(nbor_adjacency.id());
			continue;
		}
		const auto actual_clockwise_nbor = node_2.neighbor_clockwise_of(nbor_adjacency.id());
		if (!actual_clockwise_nbor.has_value()) {
			FAIL() << "neighbor " << static_cast<std::size_t>(nbor_adjacency.id()) << " had no clockwise neighbor";
			continue;
		}
		EXPECT_EQ(*expected_clockwise_nbor_id, actual_clockwise_nbor->id());
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
	for (const wl::MapNode::Adjacency nbor_adjacency : node_2.neighbors()) {
		const auto expected_counter_clockwise_nbor_id = expected_after(nbor_adjacency.id());
		if (!expected_counter_clockwise_nbor_id.has_value()) {
			FAIL() << "got unexpected neighbor " << static_cast<std::size_t>(nbor_adjacency.id());
			continue;
		}
		const auto actual_counter_clockwise_nbor = node_2.neighbor_counter_clockwise_of(nbor_adjacency.id());
		if (!actual_counter_clockwise_nbor.has_value()) {
			FAIL() << "neighbor " << static_cast<std::size_t>(nbor_adjacency.id()) << " had no counter-clockwise neighbor";
			continue;
		}
		EXPECT_EQ(*expected_counter_clockwise_nbor_id, actual_counter_clockwise_nbor->id());
	}

	// test that a node which is not actually a neighbor of node 2
	// has no counter-clockwise neighbor
	const auto clockwise_of_3 = node_2.neighbor_clockwise_of(wl::map_id(3u));
	EXPECT_FALSE(clockwise_of_3.has_value());
}

TEST(MapNode, default_adjacency_is_not_over_water) {
	constexpr wl::MapNode::Adjacency default_adjacency{ wl::map_id(0) };
	static_assert(!default_adjacency.is_water_border());
	EXPECT_FALSE(default_adjacency.is_water_border());
}

TEST(MapNode, sixty_six_to_ninety_eight_water_border) {
	constexpr auto k_66 = wl::map_id(66u);
	constexpr auto k_98 = wl::map_id(98u);


	const auto is_water_adjacency =
		[](const wl::MapNode::Adjacency& adjacency) noexcept -> bool {
			return adjacency.is_water_border();
		};

	{
		// Find the water border
		const auto& node_66 = default_map.map_node(k_66);
		const auto itr = std::find_if(node_66.neighbors().begin(),
			                          node_66.neighbors().end(),
			                          is_water_adjacency);
		ASSERT_NE(itr, node_66.neighbors().end());

		const wl::MapNode::Adjacency& water_adjacency = *itr;
		EXPECT_TRUE(water_adjacency.is_water_border());
		EXPECT_EQ(k_98, water_adjacency.id());

		// Make sure there is only 1 water border
		const auto next_water_border_itr = std::find_if(itr + 1,
			                                            node_66.neighbors().end(),
			                                            is_water_adjacency);
		EXPECT_EQ(next_water_border_itr, node_66.neighbors().end());
	}

	{
		// Find the water border
		const auto& node_98 = default_map.map_node(k_98);
		const auto itr = std::find_if(node_98.neighbors().begin(),
			node_98.neighbors().end(),
			is_water_adjacency);
		ASSERT_NE(itr, node_98.neighbors().end());

		const wl::MapNode::Adjacency& water_adjacency = *itr;
		EXPECT_TRUE(water_adjacency.is_water_border());
		EXPECT_EQ(k_66, water_adjacency.id());

		// Make sure there is only 1 water border
		const auto next_water_border_itr = std::find_if(itr + 1,
			node_98.neighbors().end(),
			is_water_adjacency);
		EXPECT_EQ(next_water_border_itr, node_98.neighbors().end());
	}
}

TEST(MapNode, is_not_adjacent_to_self) {
	wl::MapNode::ID i{ 0u };
	for (const auto& map_node : default_map.map_nodes())
	{
		EXPECT_FALSE(map_node.is_adjacent_to(i));
		++i;
	}
}

TEST(MapNode, all_adjacencies_are_bidirectional) {
	wl::MapNode::ID original_id{ 0u };
	const wl::MapNode::ID max_id_implemented{ static_cast<std::uint16_t>(default_map.map_nodes().size() - 1) };
	for (const auto& map_node : default_map.map_nodes())
	{
		for (const auto& adjacency : map_node.neighbors())
		{
			const auto adjacent_id = adjacency.id();
			if (adjacent_id > max_id_implemented)
			{
				continue;
			}
			const auto& adjacent_node = default_map.map_node(adjacent_id);
			EXPECT_TRUE(adjacent_node.is_adjacent_to(original_id)) << static_cast<size_t>(adjacent_id) << " is not adjacent to " << static_cast<size_t>(original_id);
		}
		++original_id;
	}
}
