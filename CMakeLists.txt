cmake_minimum_required(VERSION 3.0.0)

project(duration_timer)

include_directories (
    ${CMAKE_SOURCE_DIR}/include
)

set(duration_timer_SRC
    ${CMAKE_SOURCE_DIR}/src/duration_timer.cpp
)

add_library(duration_timer src/duration_timer.cpp)

add_executable(timer_example example/timer_example.cpp)
target_link_libraries(timer_example duration_timer)