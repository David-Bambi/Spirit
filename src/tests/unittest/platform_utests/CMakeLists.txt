add_subdirectory(builder)
add_subdirectory(object)
add_subdirectory(profiler)

add_custom_target(platform_utests DEPENDS buildertest objecttest profilertest)
