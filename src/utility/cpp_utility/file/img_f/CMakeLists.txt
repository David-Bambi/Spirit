cmake_minimum_required(VERSION 3.10)

add_library(raster_f SHARED ./ppm/ppm_f.cpp
                            ./ppm/ppm_obj.cpp)

# Activer les avertissements pour les compilateurs GCC et Clang
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(raster_f PRIVATE -Wall -Wextra -Wpedantic)
endif()

target_include_directories(raster_f PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} )
target_link_libraries(raster_f GTest::gtest_main)

