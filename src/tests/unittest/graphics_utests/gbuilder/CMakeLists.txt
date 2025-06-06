set(GBUILDER_TEST_EXE gbuildertest)
set(GBUILDER_TEST_NAME graphics_gbuildertest)
set(GBUILDER_TEST_SRC gappbuildertest.cpp meshbuildertest.cpp)

add_executable(${GBUILDER_TEST_EXE} ${GBUILDER_TEST_SRC})

target_link_libraries(${GBUILDER_TEST_EXE}
                      PRIVATE ${GRAPHICS_TEST_EXTERNAL_LIB})

add_test(NAME ${GBUILDER_TEST_NAME} COMMAND ${GBUILDER_TEST_EXE})
