set(GRAPHICI_TEST_LIB
    s_graphics
    s_platform
    s_algorithm
    glfw)
set(GRAPHICI_TEST_INC ${EXTERNAL_LIB_DIR} ${CMAKE_SOURCE_DIR} .)

add_subdirectory(mesh/triangle)
add_subdirectory(mesh/triangle_color)
add_subdirectory(mesh/rectangle)
add_subdirectory(mesh/cube)
add_subdirectory(model/update_function)
add_subdirectory(model/ground_model)
add_subdirectory(texture/basic)
add_subdirectory(texture/multiple_texture)
add_subdirectory(texture/texture_and_color)
add_subdirectory(camera/camera_static)
add_subdirectory(camera/camera_movement)
add_subdirectory(component/transform_translate)
add_subdirectory(component/transform_rotate)
add_subdirectory(component/transform_scale)
