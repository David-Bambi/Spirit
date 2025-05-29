set(SINGLETON_TEST_EXE singletontest)
set(SINGLETON_TEST_NAME platform_singletontest)
set(SINGLETON_TEST_EXTERNAL_LIB s_platform Catch2::Catch2WithMain
                                spdlog::spdlog)
set(SINGLETON_TEST_SRC singletontest.cpp)

add_executable(${SINGLETON_TEST_EXE} ${SINGLETON_TEST_SRC})

target_link_libraries(${SINGLETON_TEST_EXE}
                      PRIVATE ${SINGLETON_TEST_EXTERNAL_LIB})

add_test(NAME ${SINGLETON_TEST_NAME} COMMAND ${SINGLETON_TEST_EXE})
