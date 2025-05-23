set(TRACER_TEST_EXE tracertest)
set(TRACER_TEST_NAME platform_tracertest)
set(TRACER_TEST_EXTERNAL_LIB s_platform Catch2::Catch2WithMain spdlog::spdlog)
set(TRACER_TEST_SRC tracertest.cpp)

add_executable(${TRACER_TEST_EXE} ${TRACER_TEST_SRC})

target_link_libraries(${TRACER_TEST_EXE}
                      PRIVATE ${TRACER_TEST_EXTERNAL_LIB})

add_test(NAME ${TRACER_TEST_NAME} COMMAND ${TRACER_TEST_EXE})
