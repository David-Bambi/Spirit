add_subdirectory(builder)

add_custom_target(platform_utests DEPENDS buildertest)
