set(TEXTUREBASIC_I_TEST_EXE texturebasicitestexe)
set(TEXTUREBASIC_I_TEST_NAME sgraphic_texturebasic)
set(TEXTUREBASIC_I_TEST_SRC TextureBasicITest.cpp)

file(COPY shader DESTINATION ".")
file(COPY texture DESTINATION ".")

add_executable(${TEXTUREBASIC_I_TEST_EXE} TextureBasicITest.cpp)

target_link_libraries(${TEXTUREBASIC_I_TEST_EXE} PRIVATE ${GRAPHICI_TEST_LIB})

target_include_directories(${TEXTUREBASIC_I_TEST_EXE}
                           PRIVATE ${GRAPHICI_TEST_INC})

add_test(NAME ${TEXTUREBASIC_I_TEST_NAME} COMMAND ${TEXTUREBASIC_I_TEST_EXE})
