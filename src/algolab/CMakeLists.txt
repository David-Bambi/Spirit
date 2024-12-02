
set(Java_RUNTIME /usr/bin/java)

# Outil pour compiler le java
include(UseJava)
include(${PROJECT_SOURCE_DIR}/cmake_utils/CMakeJavaUtils.cmake)
find_package(Java REQUIRED)
 

# compilation de mon projet algolab
set(ALGOLAB_PROJECT algolab)
project (${ALGOLAB_PROJECT} NONE) 



set(FILE_TO_COMPILE
    algolab/Algolab
    array_utility/ArrU) 

create_jar(${ALGOLAB_PROJECT} "${FILE_TO_COMPILE}")