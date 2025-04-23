set(TEXTUREANDCOLOR_I_TEST_EXE textureandcoloritestexe)
set(TEXTUREANDCOLOR_I_TEST_NAME sgraphic_textureandcolor)
set(TEXTUREANDCOLOR_I_TEST_SRC TextureAndColorITests.cpp)

file(COPY shader DESTINATION ".")
file(COPY texture DESTINATION ".")

add_executable(${TEXTUREANDCOLOR_I_TEST_EXE} TextureAndColorITests.cpp)

target_link_libraries(${TEXTUREANDCOLOR_I_TEST_EXE} 
                      PRIVATE 
                      ${GRAPHICI_TEST_LIB})
                      
target_include_directories(${TEXTUREANDCOLOR_I_TEST_EXE} 
                           PRIVATE 
                           ${GRAPHICI_TEST_LIB})

add_test(NAME ${TEXTUREANDCOLOR_I_TEST_NAME} 
         COMMAND ${TEXTUREANDCOLOR_I_TEST_EXE})