set(GOBJECT_TEST_EXE gobjecttest)
set(GOBJECT_TEST_NAME graphics_gobjecttest)
set(GOBJECT_TEST_SRC gobjecttest.cpp)

add_executable(${GOBJECT_TEST_EXE} ${GOBJECT_TEST_SRC})

target_link_libraries(${GOBJECT_TEST_EXE} PRIVATE ${GRAPHICS_TEST_EXTERNAL_LIB})

add_test(NAME ${GOBJECT_TEST_NAME} COMMAND ${GOBJECT_TEST_EXE})

set(GID_TEST_EXE gidtest)
set(GID_TEST_NAME graphics_gidtest)
set(GID_TEST_SRC gidtest.cpp)

add_executable(${GID_TEST_EXE} ${GID_TEST_SRC})

target_link_libraries(${GID_TEST_EXE} PRIVATE ${GRAPHICS_TEST_EXTERNAL_LIB})

add_test(NAME ${GID_TEST_NAME} COMMAND ${GID_TEST_EXE})
