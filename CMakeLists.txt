cmake_minimum_required(VERSION 3.10)

set (Spirit spirit_project)

set(MAJOR_VERSION 1)
set(MINOR_VERSION 0)
set(CMAKE_BUILD_TYPE Debug)

project(${Spirit} VERSION ${MAJOR_VERSION}.${MINOR_VERSION})

include(CTest)
enable_testing()

# set (CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")
# set (CMAKE_LINKER_FLAGS_DEBUG "${CMAKE_LINKER_FLAGS_DEBUG} -fno-omit-frame-pointer -fsanitize=address")

include(FetchContent)
FetchContent_Declare(
    googletest 
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG        v1.15.2
)
FetchContent_MakeAvailable(googletest)

set(CMAKE_LIBS_DIR ${CMAKE_BINARY_DIR}/lib)

# add_subdirectory(src/tests)
# add_subdirectory(src/ptr_dyna_stat)
# add_subdirectory(src/raster_f)
# add_subdirectory(src/java_src)
add_subdirectory(src/utility) 