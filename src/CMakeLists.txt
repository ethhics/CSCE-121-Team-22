cmake_minimum_required(VERSION 2.6)
project (PROJECT)

set(CMAKE_CXX_FLAGS "-g -std=c++17 -Wall -Wextra -pedantic")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../bin)

find_package(FLTK)

add_library(ourlib tile.cpp calculator.cpp splash_screen.cpp
	highscore_screen.cpp game_screen.cpp initials_screen.cpp)
add_library(dependencies ../include/Graph.cpp ../include/GUI.cpp
	../include/Simple_window.cpp ../include/Window.cpp)
set(LIBS ${FLTK_LIBRARY} ${FLTK_IMAGES_LIBRARY} dependencies ourlib)

# Tests
add_executable(tile_test test/tile_tests.cpp)
add_executable(calculator_test test/calculator_tests.cpp)
add_executable(highscore_test test/highscore_tests.cpp)

target_link_libraries(tile_test ourlib)
target_link_libraries(calculator_test ourlib)
target_link_libraries(highscore_test ${LIBS})

# Windows
add_executable(splash_window window/splash_test.cpp)
add_executable(highscore_window window/highscore_test.cpp)
add_executable(game_window window/game_test.cpp)

target_link_libraries(splash_window ${LIBS})
target_link_libraries(highscore_window ${LIBS} dependencies)
target_link_libraries(game_window ${LIBS})

# Main
add_executable(PROJECT main.cpp)

target_link_libraries(PROJECT ${LIBS} dependencies)
