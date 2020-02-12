cmake_minimum_required(VERSION 3.10)
project(algos)

set(CMAKE_CXX_STANDARD 14)

include_directories(SYSTEM ./lib)

add_executable(algos_1 Part1/2025.cpp)
add_executable(algos_2 Part1/1005.cpp)
add_executable(algos_3 Part1/1155.cpp)
add_executable(algos_4 Part1/1296.cpp)
add_executable(algos_5 Part1/1401.cpp)
add_executable(algos_6 Part2/1207.cpp)
add_executable(algos_7 Part2/1444.cpp)
add_executable(algos_8 Part2/1604.cpp)
add_executable(algos_9 Part2/1726.cpp)
add_executable(algos_10 Part2/1322.cpp)