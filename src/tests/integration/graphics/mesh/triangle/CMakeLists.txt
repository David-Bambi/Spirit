set(TRIANGLE_I_TEST_EXE triangleitestexe)
set(TRIANGLE_I_TEST_NAME sgraphic_triangle)
set(TRIANGLE_I_TEST_SRC TriangleITest.cpp)

file(COPY shader DESTINATION ".")

add_executable(${TRIANGLE_I_TEST_EXE} TriangleITest.cpp)

target_link_libraries(${TRIANGLE_I_TEST_EXE} PRIVATE ${GRAPHICI_TEST_LIB})

target_include_directories(${TRIANGLE_I_TEST_EXE} PRIVATE ${GRAPHICI_TEST_INC})

add_test(NAME ${TRIANGLE_I_TEST_NAME} COMMAND ${TRIANGLE_I_TEST_EXE})
