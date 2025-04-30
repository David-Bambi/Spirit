set(src_sc
    ${src_sc}
    ./Recipe/Recipe.cpp
    ./Recipe/RecipeMgr.cpp
    ./Material/Material.cpp
    ./Material/MaterialMgr.cpp
    ./SatisfactoryCalculator.cpp)

add_executable(SC ${src_sc})
target_include_directories(SC PUBLIC ".")

set_target_properties(SC PROPERTIES CXX_STANDARD 23)

target_compile_options(SC PRIVATE /W3)

target_link_libraries(SC PUBLIC DC TUI)
target_include_directories(SC PUBLIC ../DC ../TUI)
