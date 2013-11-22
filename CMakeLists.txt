cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_FLAGS "-std=c++0x")

include_directories(eigen)

include_directories(lib/include)
add_subdirectory(lib)

set(ALL_LIBRARIES gca)

add_subdirectory(application)