MAKEFLAGS += --no-print-directory

all :  cmk 

rebuild :
	rm -rf build
	mkdir build

cmk : 
	cmake -S . -B build -G Ninja && cmake --build build  --target run_cmake_format

doc :
	rm -rf docs/html
	rm -rf docs/latex
	cmake --build build --config Debug --target docs_spirit

graphics :
	cmake --build build --config Debug --target s_graphics

itests :
	cmake --build build --config Debug --target itests

gf :
	ninja -C build && ./build/src/app/gf/gf.exe
