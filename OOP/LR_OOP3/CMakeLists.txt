cmake_minimum_required (VERSION 3.5)
project (oop_exercise_03)
add_executable(oop_exercise_03
main.cpp
hexagon.cpp
octagon.cpp
triangle.cpp
point.cpp
)

set(CMAKE_CXX_FLAGS
    "${CMAKE_CXX_FLAGS} -Wall -Wextra")