cmake_minimum_required(VERSION 2.6)
project (PROJECT)

set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -pedantic")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../bin)

find_package(FLTK)

add_library(ourlib tile.cpp calculator.cpp)
add_library(dependencies ../include/Graph.cpp ../include/GUI.cpp
	../include/Simple_window.cpp ../include/Window.cpp)
set(LIBS ${FLTK_LIBRARY} ${FLTK_IMAGES_LIBRARY} dependencies ourlib)

# Tests
add_executable(tile_test test/tile_tests.cpp)
target_link_libraries(tile_test ourlib)
add_executable(calculator_test test/calculator_tests.cpp)
target_link_libraries(calculator_test ourlib)
add_executable(highscore_test test/highscore_tests.cpp)
target_link_libraries(highscore_test ${LIBS})

# Windows
add_executable(splashscreen_test splash_screen.cpp)
add_executable(highscorescreen_test highscore_screen.cpp)
add_executable(gamescreen_test game_screen.cpp)

target_link_libraries(splashscreen_test ${LIBS})
target_link_libraries(highscorescreen_test ${LIBS})
target_link_libraries(gamescreen_test ${LIBS})

