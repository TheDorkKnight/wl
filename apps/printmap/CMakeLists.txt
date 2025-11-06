cmake_minimum_required(VERSION 3.10)
project(PrintMapApp)

include(../../cmake/wl.cmake)

add_executable(printmap src/main.cpp)
target_link_libraries(printmap PRIVATE wl)
