set(src_tui
    ${src_tui}
    TMeter/TMeter.cpp
    TList/TList.tpp
    TAskUser/TAskUser_inst.cpp
    TChoice/TChoiceList.cpp)

add_library(TUI STATIC ${src_tui})

set_target_properties(TUI PROPERTIES CXX_STANDARD 23)
target_compile_options(TUI PRIVATE /W3)
target_include_directories(TUI PUBLIC "." "..")

# Test integration
add_subdirectory(TUI_IntegrationTest)

# Test unitaires
# add_subdirectory(TUI_UnitTest)
