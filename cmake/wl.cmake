
add_library(wl INTERFACE)
target_include_directories(wl INTERFACE ${CMAKE_CURRENT_LIST_DIR}/../include)
target_compile_features(wl INTERFACE cxx_std_20)
