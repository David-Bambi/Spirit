cmake_minimum_required (VERSION 3.10)

# Project informations
set(Wool wool_project)

set(MAJOR_VERSION 1)
set(MINOR_VERSION 0)
set(CMAKE_BUILD_TYPE Debug)


# Add the project
project(${Wool} VERSION ${MAJOR_VERSION}.${MINOR_VERSION})

include(CTest)
enable_testing()

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_compile_options(/W2)
endif()

# Configure header file
configure_file(cmake/Config.h.in cmakeconfig/Config.h)

# google test framework
add_subdirectory(googletest)
include(GoogleTest) # To use gtest_discover_tests
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

include(cmake/sourcelist.cmake)
include(cmake/subdirectory.cmake)

add_subdirectory(shaders)
add_subdirectory(textures)

#target_link_libraries(${Wool} PRIVATE glfw3dll)

