cmake_minimum_required(VERSION 3.10)

add_library(pixel_img SHARED ./piximg.cpp)

# Activer les avertissements pour les compilateurs GCC et Clang
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(raster_f PRIVATE -Wall -Wextra -Wpedantic)
endif()

target_include_directories(pixel_img PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
