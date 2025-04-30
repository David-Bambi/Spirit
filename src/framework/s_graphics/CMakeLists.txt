set(S_GRAPHICS_LIB s_graphics)

set(S_GRAPHICS_SRC
    camera/CameraBuilder.cpp
    camera/Camera.cpp
    input/Input.cpp
    model/Mesh.cpp
    model/Vertices.cpp
    model/MeshBuilder.cpp
    model/Model.cpp
    model/ModelBuilder.cpp
    component/Transform.cpp
    texture/Texture.cpp
    texture/TextureBuilder.cpp
    time/Time.cpp
    shader_program/ShaderProg.cpp
    scene/Scene.cpp
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
target_enable_lto(${S_GRAPHICS_LIB} TRUE)
target_set_warnings(${S_GRAPHICS_LIB} TRUE FALSE)

# Documentation target
set(S_GRAPHICS_DOC s_graphics_doc)
set(S_GRAPHICS_DOC_PATH ${CMAKE_SOURCE_DIR}/docs/framework/s_graphics)
target_generate_docs(${S_GRAPHICS_DOC} ${S_GRAPHICS_DOC_PATH})

if(TARGET ${S_GRAPHICS_DOC})
    add_dependencies(${S_GRAPHICS_LIB} ${S_GRAPHICS_DOC})
endif()

set(S_GRAPHICS_UML s_graphics_uml)
set(S_GRAPHICS_UML_PATH ${CMAKE_SOURCE_DIR}/docs/framework/s_graphics/uml)
target_generate_uml(${S_GRAPHICS_UML} ${S_GRAPHICS_UML_PATH})

if(TARGET ${S_GRAPHICS_UML})
    add_dependencies(${S_GRAPHICS_LIB} ${S_GRAPHICS_UML})
endif()

# Clang-tidy target
set(S_GRAPHICS_CLANGTIDY s_graphics_clangtidy)
target_add_clang_tidy(${S_GRAPHICS_CLANGTIDY} ${S_GRAPHICS_LIB})

if (TARGET ${S_GRAPHICS_CLANGTIDY})
add_dependencies(${S_GRAPHICS_LIB} ${S_GRAPHICS_CLANGTIDY})
endif()

# Clang-format target
set(S_GRAPHICS_CLANGFORMAT s_graphics_clangformat)
target_add_clang_format(${S_GRAPHICS_CLANGFORMAT})

if (TARGET ${S_GRAPHICS_CLANGFORMAT})
add_dependencies(${S_GRAPHICS_LIB} ${S_GRAPHICS_CLANGFORMAT})
endif()
