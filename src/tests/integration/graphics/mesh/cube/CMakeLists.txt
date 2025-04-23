set(CUBE_I_TEST_EXE cubeitestexe)
set(CUBE_I_TEST_NAME sgraphic_cube)
set(CUBE_I_TEST_SRC CubeITest.cpp)

file(COPY shader DESTINATION ".")

add_executable(${CUBE_I_TEST_EXE} CubeITest.cpp)

target_link_libraries(${CUBE_I_TEST_EXE} 
                      PRIVATE 
                      ${GRAPHICI_TEST_LIB})
                      
target_include_directories(${CUBE_I_TEST_EXE} 
                           PRIVATE 
                           ${GRAPHICI_TEST_INC})

add_test(NAME ${CUBE_I_TEST_NAME} 
         COMMAND ${CUBE_I_TEST_EXE})