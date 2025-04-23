# Fichier source et include pour la librarie
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
                   scene/Renderer.cpp
                   shader_program/ShaderProg.cpp
                   scene/Scene.cpp
                   scene/SceneObject.cpp
                   uglad/uglad.cpp
                   uglfw/uglfw.cpp)

set(S_GRAPHICS_EXTERNAL_SRC ${EXTERNAL_LIB_DIR}/glad/glad.c ${EXTERNAL_LIB_DIR}/stb_image/stb_image.cpp)

set(S_GRAPHICS_INC ${CMAKE_CURRENT_SOURCE_DIR})

set(S_GRAPHICS_EXTERAL_LIB glfw s_type s_platform)

# Compilation de la librarie
add_library(${S_GRAPHICS_LIB} SHARED ${S_GRAPHICS_SRC} ${S_GRAPHICS_EXTERNAL_SRC})
target_include_directories(${S_GRAPHICS_LIB} PUBLIC ${S_GRAPHICS_INC} ${EXTERNAL_LIB_DIR})
target_link_libraries(${S_GRAPHICS_LIB} PRIVATE  ${S_GRAPHICS_EXTERAL_LIB})
