set(GOBJECT_TEST_EXE gobjecttest)
set(GOBJECT_TEST_NAME graphics_gobjecttest)
set(GOBJECT_TEST_EXTERNAL_LIB s_graphics Catch2::Catch2WithMain)
set(GOBJECT_TEST_SRC gobjecttest.cpp)

add_executable(${GOBJECT_TEST_EXE} ${GOBJECT_TEST_SRC})

target_link_libraries(${GOBJECT_TEST_EXE} PRIVATE ${GOBJECT_TEST_EXTERNAL_LIB})

add_test(NAME ${GOBJECT_TEST_NAME} COMMAND ${GOBJECT_TEST_EXE})
