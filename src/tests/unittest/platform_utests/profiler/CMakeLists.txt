set(PROFILER_TEST_EXE profilertest)
set(PROFILER_TEST_NAME platform_profilertest)
set(PROFILER_TEST_EXTERNAL_LIB s_platform Catch2::Catch2WithMain spdlog::spdlog)
set(PROFILER_TEST_SRC profilertest.cpp)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/reflogs
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/${PROFILER_TEST_NAME})

add_executable(${PROFILER_TEST_EXE} ${PROFILER_TEST_SRC})

target_link_libraries(${PROFILER_TEST_EXE}
                      PRIVATE ${PROFILER_TEST_EXTERNAL_LIB})

add_test(NAME ${PROFILER_TEST_NAME} COMMAND ${PROFILER_TEST_EXE})
