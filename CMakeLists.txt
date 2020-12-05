cmake_minimum_required (VERSION 3.15)
project(algorithms)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fsanitize=address")

add_executable(algorithms main.cpp testing.cpp algorithms.cpp)
