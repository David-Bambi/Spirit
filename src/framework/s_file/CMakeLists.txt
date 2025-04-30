set(S_FILE_LIB s_file)

set(S_FILE_SRC ppm/ppm_f.cpp ppm/ppm_obj.cpp)

set(S_FILE_INC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(${S_FILE_LIB} SHARED ${S_FILE_SRC})

target_include_directories(${S_FILE_LIB} PUBLIC ${S_FILE_INC})
