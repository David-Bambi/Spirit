MAKEFLAGS += --no-print-directory 

BUILD_TYPE ?= debug

OPT ?= none
OPT_SANITIZER = OFF
OPT_WARNINGS = OFF
OTP_DOCUMENTATION = OFF
OTP_CLANGTIDY = OFF
OTP_CLANGFORMAT = OFF
OPT_LTO = OFF

ifeq ($(OPT), all)
	OPT_SANITIZER = ON
	OPT_WARNINGS = ON
	OPT_LTO = ON
	OTP_DOCUMENTATION = ON
	OTP_CLANGTIDY = ON
	OTP_CLANGFORMAT = ON
endif

ifeq ($(BUILD_TYPE), debug)
	BUILD_DIR = build/debug
else ifeq ($(BUILD_TYPE), release)
	BUILD_DIR = build/release
else
	$(error Invalid BUILD_TYPE: $(BUILD_TYPE))
endif

lsconfig :
	@echo $(BUILD_TYPE)
	@echo $(BUILD_DIR)
	@echo $(OPT_SANITIZER)
	@echo $(OPT_WARNINGS)
	@echo $(OPT_LTO)
	@echo $(OTP_DOCUMENTATION)
	@echo $(OTP_CLANGTIDY)
	@echo $(OTP_CLANGFORMAT)


rebuild :
	rm -rf build
	mkdir build

cmk : 
	cmake -S . -B $(BUILD_DIR) -G Ninja -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) -DSANITIZER_OPT=${OPT_SANITIZER} \
	-DWARNINGS_OPT=${OPT_WARNINGS} -DLTO_OPT=${OPT_LTO} -DDOCUMENTATION_OPT=${OTP_DOCUMENTATION} -DCLANGTIDY_OPT=${OTP_CLANGTIDY} \
	-DCLANGFORMAT_OPT=${OTP_CLANGFORMAT} && cmake  --build $(BUILD_DIR) --target run_cmake_format 

graphics :
	cmake --build $(BUILD_DIR) --config Debug --target s_graphics
	
gfbuild :
	cmake --build $(BUILD_DIR) --config Debug --target gf

gf :
	./$(BUILD_DIR)/src/app/gf/gf 

platform :
	cmake --build  $(BUILD_DIR) --target s_platform \
	&& cmake --build $(BUILD_DIR) --target platform_utests \
	&& ctest --output-on-failure --test-dir ./$(BUILD_DIR)/src/tests/unittest/platform_utests


glad :
	cmake --build $(BUILD_DIR) --config Debug --target glad

itests :
	cmake --build $(BUILD_DIR) --config Debug --target itests

utests :
	cmake --build $(BUILD_DIR) --config Debug --target utests

sharedptr : 
	cmake --build $(BUILD_DIR) --config Debug --target sharedptr && ./$(BUILD_DIR)/src/app/sharedptr/sharedptr

