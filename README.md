# CSCE-121-Team-22
==================

This repository, located online at https://github.com/zmscott5/CSCE-121-Team-22, contains the source code for Team 22's term project in CSCE 121 during the Fall 2016 semester, under Dr. Walter Daugherity.

By Joseph Rangel, Michael Schmaus, and Zach Scott

## How to compile
FLTK is required to compile this project.

In this project's root directory (which contains this file) run `make init` to run CMake and generate the required build setup for your system. Then, run `make` to build the actual project.

If CMake is not installed on your machine, you may alternately run `make simple` to generate the main project executable.

If your environment does not include Make, the files needed to build the project are `src/*.cpp` and `include/*.cpp`. Make sure not to include `src/test/*` and `src/window/*` when compiling in this situation. Be sure to link `fltk` and `fltk_images`.

If your environment does not include a C++ compiler, ask a friend that does to compile this for you!

## How to run
After compiling, in the project root directory run `bin/PROJECT`. Also included in the `bin/` folder are test cases for multiple parts of program that are automatically generated.

## How to play
After the splash screen, a page explaining how to play the game will appear. This will cover all aspects of the game. The following screen shows high scores for all difficulties and also allows you to start a game at your specified difficulty. After the game completes, your scored will show and after entering your initials the high score screen for your difficulty will be shown, updated with your latest score. Clicking next will bring you back to the original high score screen.

## How to exit
To exit the program simply close out of the difficulty selection/high score window. The program's behavior when exited at any other point is undefined.
