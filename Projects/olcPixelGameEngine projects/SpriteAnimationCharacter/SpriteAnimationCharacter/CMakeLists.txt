cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

project(sample)

add_executable(
    sample
    main.cpp
)

target_link_libraries(sample -lX11 -lGL -lpthread -lpng -lstdc++fs)
