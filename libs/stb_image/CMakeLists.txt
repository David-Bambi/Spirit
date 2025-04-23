set(S_STBIMG_LIB stb_image_lib)

set(S_STBIMG_SRC stb_image.cpp)

set(S_STBIMG_INC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(${S_STBIMG_LIB} SHARED ${S_STBIMG_SRC})

target_include_directories(${S_STBIMG_LIB} PUBLIC ${S_STBIMG_INC})