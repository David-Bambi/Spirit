set(GRAPHICS_TEST_EXTERNAL_LIB
    glad
    glfw
    s_graphics
    s_platform
    Catch2::Catch2WithMain
    nlohmann_json
    glad)

add_subdirectory(gres)
add_subdirectory(gbuilder)
add_subdirectory(gimporter)
add_subdirectory(gobject)

add_custom_target(
    graphics_utests DEPENDS 
                        gbuildertest
                        gidtest
                        gimportertest
                        gobjecttest
                        grestest
        )
