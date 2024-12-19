cmake_minimum_required(VERSION 3.10)

add_executable(ppm_test ppm_tests.cpp
                        ppm_f_test.cpp
                        ppm_obj_test.cpp)

target_include_directories(ppm_test PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ppm_test raster_f GTest::gtest_main )

include(GoogleTest)
gtest_discover_tests(ppm_test)

