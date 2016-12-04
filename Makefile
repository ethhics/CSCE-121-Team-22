all:
	cd build && make

init: clean_up run_cmake

clean_up:
	rm -f bin/*

run_cmake:
	cmake -Bbuild -Hsrc

simple: clean_up
	g++ -std=c++17 include/*.cpp src/*.cpp -o bin/PROJECT -lfltk -lfltk_images
