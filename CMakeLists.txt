cmake_minimum_required(VERSION 3.22)
project(convert)

set(CMAKE_C_STANDARD 23)

add_executable(angle src/angle.cpp)

add_executable(temperature src/temperature.cpp)
