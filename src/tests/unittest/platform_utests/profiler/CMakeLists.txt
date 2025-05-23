set(PROFILER_TEST_EXE profilertest)
set(PROFILER_TEST_NAME platform_profilertest)
set(PROFILER_TEST_EXTERNAL_LIB s_platform Catch2::Catch2WithMain spdlog::spdlog)
set(PROFILER_TEST_SRC profilertest.cpp)

add_executable(${PROFILER_TEST_EXE} ${PROFILER_TEST_SRC})

target_link_libraries(${PROFILER_TEST_EXE}
                      PRIVATE ${PROFILER_TEST_EXTERNAL_LIB})

add_test(NAME ${PROFILER_TEST_NAME} COMMAND ${PROFILER_TEST_EXE})
