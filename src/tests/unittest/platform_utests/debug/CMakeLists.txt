set(DEBUG_TEST_EXTERNAL_LIB s_platform Catch2::Catch2WithMain spdlog::spdlog)

set(TRACEABLE_TEST_EXE traceabletest)
set(TRACEABLE_TEST_NAME platform_traceabletest)
set(TRACEABLE_TEST_SRC traceabletest.cpp)
add_executable(${TRACEABLE_TEST_EXE} ${TRACEABLE_TEST_SRC})
target_link_libraries(${TRACEABLE_TEST_EXE} PRIVATE ${DEBUG_TEST_EXTERNAL_LIB})
add_test(NAME ${TRACEABLE_TEST_NAME} COMMAND ${TRACEABLE_TEST_EXE})

set(PROFILER_TEST_EXE profilertest)
set(PROFILER_TEST_NAME platform_profilertest)
set(PROFILER_TEST_SRC profilertest.cpp)
add_executable(${PROFILER_TEST_EXE} ${PROFILER_TEST_SRC})
target_link_libraries(${PROFILER_TEST_EXE} PRIVATE ${DEBUG_TEST_EXTERNAL_LIB})
add_test(NAME ${PROFILER_TEST_NAME} COMMAND ${PROFILER_TEST_EXE})

set(TRACER_TEST_EXE tracertest)
set(TRACER_TEST_NAME platform_tracertest)
set(TRACER_TEST_SRC tracertest.cpp)
add_executable(${TRACER_TEST_EXE} ${TRACER_TEST_SRC})
target_link_libraries(${TRACER_TEST_EXE} PRIVATE ${DEBUG_TEST_EXTERNAL_LIB})
add_test(NAME ${TRACER_TEST_NAME} COMMAND ${TRACER_TEST_EXE})

set(TRACEABLEPROFILER_TEST_EXE traceableprofilertest)
set(TRACEABLEPROFILER_TEST_NAME platform_traceableprofilertest)
set(TRACEABLEPROFILER_TEST_SRC traceableprofilertest.cpp)
add_executable(${TRACEABLEPROFILER_TEST_EXE} ${TRACEABLEPROFILER_TEST_SRC})
target_link_libraries(${TRACEABLEPROFILER_TEST_EXE}
                      PRIVATE ${DEBUG_TEST_EXTERNAL_LIB})
add_test(NAME ${TRACEABLEPROFILER_TEST_NAME}
         COMMAND ${TRACEABLEPROFILER_TEST_EXE})
