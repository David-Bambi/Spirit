add_subdirectory(builder)
add_subdirectory(debug)
add_subdirectory(object)
add_subdirectory(singleton)

add_custom_target(
    platform_utests
    DEPENDS buildertest
            objecttest
            profilertest
            singletontest
            traceabletest
            traceableprofilertest
            tracertest)
