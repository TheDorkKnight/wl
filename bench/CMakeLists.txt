cmake_minimum_required(VERSION 3.10)
project(WLBench)

# find google benchmark
find_package(benchmark REQUIRED)

set(WL_BENCH_SOURCES 
    block_iterator_bench.cpp
)

include (../cmake/wl.cmake)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    message(STATUS "Setting build type to 'Release' as none was specified.")
    set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build, e.g. Debug, Release, RelWithDebInfo, MinSizeRel." FORCE)
endif()

add_executable(wl_bench ${WL_BENCH_SOURCES})
target_link_libraries(wl_bench PRIVATE wl benchmark::benchmark benchmark::benchmark_main)
