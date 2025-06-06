set(GRES_TEST_EXE grestest)
set(GRES_TEST_NAME graphics_grestest)
set(GRES_TEST_SRC grestest.cpp)

add_executable(${GRES_TEST_EXE} ${GRES_TEST_SRC})

target_link_libraries(${GRES_TEST_EXE} PRIVATE ${GRAPHICS_TEST_EXTERNAL_LIB})

add_test(NAME ${GRES_TEST_NAME} COMMAND ${GRES_TEST_EXE})

