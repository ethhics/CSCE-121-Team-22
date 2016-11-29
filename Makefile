all:
	cd build && make

init: clean_up run_cmake

clean_up:
	rm -f bin/*

run_cmake:
	cmake -Bbuild -Hsrc

