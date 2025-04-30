set(RECTANGLE_I_TEST_EXE rectangleitestexe)
set(RECTANGLE_I_TEST_NAME sgraphic_rectangle)
set(RECTANGLE_I_TEST_SRC RectangleITest.cpp)

file(COPY shader DESTINATION ".")

add_executable(${RECTANGLE_I_TEST_EXE} RectangleITest.cpp)

target_link_libraries(${RECTANGLE_I_TEST_EXE} PRIVATE ${GRAPHICI_TEST_LIB})

target_include_directories(${RECTANGLE_I_TEST_EXE} PRIVATE ${GRAPHICI_TEST_INC})

add_test(NAME ${RECTANGLE_I_TEST_NAME} COMMAND ${RECTANGLE_I_TEST_EXE})
