all : rebuild cmk 

rebuild :
	rm -rf build
	mkdir build

cmk : 
	cmake -S . -B build