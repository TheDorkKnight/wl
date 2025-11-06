cmake_minimum_required(VERSION 3.10)
project(WLTest)

find_package(GTest REQUIRED)

set(WL_TEST_SOURCES 
    block_iterator_test.cpp
    find_j_moves_test.cpp
    i_node_test.cpp
    investigator_abilities_test.cpp
    jack_inventory_test.cpp
    jack_move_test.cpp
    map_node_test.cpp
    no_evidence_node_test.cpp
    player_locations_test.cpp
    water_node_test.cpp
)

include (../cmake/wl.cmake)

add_executable(wl_test ${WL_TEST_SOURCES})
target_link_libraries(wl_test PRIVATE wl GTest::GTest GTest::Main)

# run the test from build
include(GoogleTest)
gtest_discover_tests(wl_test)

enable_testing()
