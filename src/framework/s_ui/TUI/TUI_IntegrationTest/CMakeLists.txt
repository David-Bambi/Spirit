add_executable(
    TUI_IntegrationTest
    TUI_IntegrationTest.cpp
    TUI_IntegrationTListTest.cpp
    TUI_IntegrationTChoiceListTest.cpp
    TUI_IntegrationTAskUserTest.cpp)

set_target_properties(TUI_IntegrationTest PROPERTIES CXX_STANDARD 23)
target_compile_options(TUI_IntegrationTest PRIVATE "/MDd")

target_link_libraries(TUI_IntegrationTest PRIVATE TUI)
target_include_directories(TUI_IntegrationTest PUBLIC "..")

set_target_properties(TUI_IntegrationTest PROPERTIES RUNTIME_OUTPUT_DIRECTORY
                                                     "${CMAKE_BINARY_DIR}/bin")
