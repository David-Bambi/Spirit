set(S_GRAPHICS_LIB s_graphics)

set(S_GRAPHICS_SRC
    camera/CameraBuilder.cpp
    camera/Camera.cpp
    gapp/Gapp.cpp
    gapp/GappBuilder.cpp
    input/Input.cpp
    mesh/Mesh.cpp
    model/Vertices.cpp
    mesh/MeshBuilder.cpp
    model/Model.cpp
    model/ModelBuilder.cpp
    component/Transform.cpp
    texture/Texture.cpp
    texture/TextureBuilder.cpp
    time/Time.cpp
    shader/ShaderProg.cpp
    scene/Scene.cpp
    ugl/ugl.cpp
    uglad/uglad.cpp
    uglfw/uglfw.cpp)

set(S_GRAPHICS_EXTERNAL_LIB
    glad
    glfw
    stb_image_lib
    s_type
    s_platform)

set(S_GRAPHICS_INC ${CMAKE_CURRENT_SOURCE_DIR})

# Create library target
add_library(${S_GRAPHICS_LIB} SHARED ${S_GRAPHICS_SRC})

target_include_directories(${S_GRAPHICS_LIB} PUBLIC ${S_GRAPHICS_INC}
                                                    ${EXTERNAL_LIB_DIR})

target_link_libraries(${S_GRAPHICS_LIB} PRIVATE ${S_GRAPHICS_EXTERNAL_LIB})

# Set target options
if(LTO_OPT)
    target_enable_lto(${S_GRAPHICS_LIB} TRUE)
endif()

if(WARNINGS_OPT)
    target_set_warnings(${S_GRAPHICS_LIB} TRUE FALSE)
endif()

# Documentation target
if(DOCUMENTATION_OPT)
    set(S_GRAPHICS_DOC s_graphics_doc)
    set(S_GRAPHICS_DOC_PATH ${CMAKE_SOURCE_DIR}/docs/framework/s_graphics)
    target_generate_docs(${S_GRAPHICS_DOC} ${S_GRAPHICS_DOC_PATH})

    add_dependencies_if_exist(${S_GRAPHICS_LIB} ${S_GRAPHICS_DOC})

    # UML target
    set(S_GRAPHICS_UML s_graphics_uml)
    set(S_GRAPHICS_UML_PATH ${CMAKE_SOURCE_DIR}/docs/framework/s_graphics/uml)
    target_generate_uml(${S_GRAPHICS_UML} ${S_GRAPHICS_UML_PATH})

    add_dependencies_if_exist(${S_GRAPHICS_LIB} ${S_GRAPHICS_UML})
endif()

# Clang-tidy target
if(CLANGTIDY_OPT)
    set(S_GRAPHICS_CLANGTIDY s_graphics_clangtidy)
    target_add_clang_tidy(${S_GRAPHICS_CLANGTIDY} ${S_GRAPHICS_LIB})

    add_dependencies_if_exist(${S_GRAPHICS_LIB} ${S_GRAPHICS_CLANGTIDY})
endif()

# Clang-format target
if(CLANGFORMAT_OPT)
    set(S_GRAPHICS_CLANGFORMAT s_graphics_clangformat)
    target_add_clang_format(${S_GRAPHICS_CLANGFORMAT})

    if(TARGET ${S_GRAPHICS_CLANGFORMAT})
        add_dependencies(${S_GRAPHICS_LIB} ${S_GRAPHICS_CLANGFORMAT})
    endif()
endif()
