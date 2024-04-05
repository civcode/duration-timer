cmake_minimum_required(VERSION 3.0.0)

project(durationtimer)

include_directories (
    ${CMAKE_SOURCE_DIR}/include
)

set(durationtimer_SRC
    ${CMAKE_SOURCE_DIR}/src/durationtimer.cpp
)

add_library(durationtimer STATIC src/duration_timer.cpp)

target_include_directories(durationtimer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(example example/timer_example.cpp)
target_link_libraries(example durationtimer)

# Install instructions are needed for FetchContent to work 
install(TARGETS durationtimer DESTINATION lib)
install(FILES include/duration_timer.h DESTINATION include)
