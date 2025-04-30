add_executable(
    DC_UnitTest
    DC_UnitTest.cpp
    DInt_UnitTest.cpp
    DStr_UnitTest.cpp
    Manager_UnitTest.cpp
    TxToTextFileStrategy_UnitTest.cpp)

set_target_properties(DC_UnitTest PROPERTIES CXX_STANDARD 23)

target_compile_options(DC_UnitTest PRIVATE "/MDd")
target_link_libraries(
    DC_UnitTest
    PUBLIC DC
           gtest
           gtest_main
           gmock
           gmock_main)
target_include_directories(DC_UnitTest PUBLIC ../Data ../Manager)

gtest_discover_tests(DC_UnitTest)
