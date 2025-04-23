set(TRIANGLE_COLOR_I_TEST_EXE trianglecoloritestexe)
set(TRIANGLE_COLOR_I_TEST_NAME sgraphic_trianglecolor)
set(TRIANGLE_COLOR_I_TEST_SRC TriangleColorITest.cpp)

file(COPY shader DESTINATION ".")

add_executable(${TRIANGLE_COLOR_I_TEST_EXE} TriangleColorITest.cpp)

target_link_libraries(${TRIANGLE_COLOR_I_TEST_EXE} 
                      PRIVATE 
                      ${GRAPHICI_TEST_LIB})
                      
target_include_directories(${TRIANGLE_COLOR_I_TEST_EXE} 
                           PRIVATE 
                           ${GRAPHICI_TEST_INC})

add_test(NAME ${TRIANGLE_COLOR_I_TEST_NAME} 
         COMMAND ${TRIANGLE_COLOR_I_TEST_EXE})
