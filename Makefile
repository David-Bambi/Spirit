MAKEFLAGS += --no-print-directory

all :  cmk 

rebuild :
	rm -rf build
	mkdir build

cmk : 
	cmake -S . -B build -G Ninja -DSANITIZER_OPT=OFF -DWARNINGS_OPT=OFF -DLTO_OPT=OFF -DDOCUMENTATION_OPT=OFF -DCLANGTIDY_OPT=OFF -DCLANGFORMAT_OPT=OFF \
 	&& cmake --build build  --target run_cmake_format 

cmk-all : 
	cmake -S . -B build -G Ninja -DSANITIZER_OPT=ON -DWARNINGS_OPT=ON -DLTO_OPT=ON -DDOCUMENTATION_OPT=ON -DCLANGTIDY_OPT=ON -DCLANGFORMAT_OPT=ON \
 	&& cmake --build build  --target run_cmake_format 

doc :
	rm -rf docs/html
	rm -rf docs/latex
	cmake --build build --config Debug --target docs_spirit

graphics :
	cmake --build build --config Debug --target s_graphics
	
gf :
	cmake --build build --config Debug --target gf

gfexe :
	./build/src/app/gf/gf

platform-all :
	cmake --build build --config Debug --target s_platform \
	&& cmake --build build --config Debug --target platform_utests \
	&& ctest --test-dir ./build/src/tests/unittest/platform_utests

platform-utest-build :
	cmake --build build --config Debug --target platform_utests


platform-utest :
	ctest --test-dir ./build/src/tests/unittest/platform_utests

glad :
	cmake --build build --config Debug --target glad

itests :
	cmake --build build --config Debug --target itests

utests :
	cmake --build build --config Debug --target utests


