set(OBJECT_TEST_EXE objecttest)
set(OBJECT_TEST_NAME platform_objecttest)
set(OBJECT_TEST_EXTERNAL_LIB s_platform Catch2::Catch2WithMain spdlog::spdlog)
set(OBJECT_TEST_SRC objecttest.cpp)

add_executable(${OBJECT_TEST_EXE} ${OBJECT_TEST_SRC})

target_link_libraries(${OBJECT_TEST_EXE} PRIVATE ${OBJECT_TEST_EXTERNAL_LIB})

add_test(NAME ${OBJECT_TEST_NAME} COMMAND ${OBJECT_TEST_EXE})
