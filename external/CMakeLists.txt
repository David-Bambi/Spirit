add_subdirectory(glfw-3.4)
add_subdirectory(stb_image)
add_subdirectory(glad)

target_set_warnings(glfw FALSE FALSE)
target_set_warnings(glad FALSE FALSE)
target_set_warnings(stb_image_lib FALSE FALSE)