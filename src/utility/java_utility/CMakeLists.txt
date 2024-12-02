set(Java_RUNTIME /usr/bin/java)

# Outil pour compiler le java
include(UseJava)
include(${PROJECT_SOURCE_DIR}/cmake_utils/CMakeJavaUtils.cmake)
find_package(Java REQUIRED)
 
# library externe au projet
add_external_jar(${PROJECT_SOURCE_DIR}/libs/jar/junit-platform-console-standalone-1.10.5.jar)


# Library to compile
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/arrayu) 
