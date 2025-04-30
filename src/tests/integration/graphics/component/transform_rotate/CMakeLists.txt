set(TRANSFORM_ROTATE_I_TEST_EXE transformrotateitestexe)
set(TRANSFORM_ROTATE_I_TEST_NAME sgraphic_transformrotate)
set(TRANSFORM_ROTATE_I_TEST_SRC TransformRotateITests.cpp)

file(COPY shader DESTINATION ".")

add_executable(${TRANSFORM_ROTATE_I_TEST_EXE} TransformRotateITests.cpp)

target_link_libraries(${TRANSFORM_ROTATE_I_TEST_EXE}
                      PRIVATE ${GRAPHICI_TEST_LIB})

target_include_directories(${TRANSFORM_ROTATE_I_TEST_EXE}
                           PRIVATE ${GRAPHICI_TEST_INC})

add_test(NAME ${TRANSFORM_ROTATE_I_TEST_NAME}
         COMMAND ${TRANSFORM_ROTATE_I_TEST_EXE})
