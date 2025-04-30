# Spirit type
# s_type is a header only library

set(S_TYPE_LIB s_type)
set(S_TYPE_INC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(${S_TYPE_LIB} INTERFACE)
target_include_directories(${S_TYPE_LIB} INTERFACE ${S_TYPE_INC})
