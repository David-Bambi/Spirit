add_executable (TUI_UnitTest
                TUI_UnitTest.cpp)
                
target_compile_options(TUI_UnitTest PRIVATE "/MDd")
target_link_libraries(TUI_UnitTest PRIVATE tui gtest gtest_main gmock gmock_main)

gtest_discover_tests(TUI_UnitTest)