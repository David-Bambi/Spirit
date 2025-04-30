set(GF_EXE gf.exe)
set(GF_INCLUDE ${EXTERNAL_LIB_DIR} ${CMAKE_SOURCE_DIR} .)
set(GF_LIBS s_graphics glfw)

add_executable(${GF_EXE} gf.cpp)

target_link_libraries(${GF_EXE} PRIVATE ${GF_LIBS})
target_include_directories(${GF_EXE} PRIVATE ${GF_INCLUDE})

target_enable_lto(${GF_EXE} TRUE)
target_set_warnings(${GF_EXE} TRUE TRUE)
target_add_clang_tidy(${GF_EXE})
target_add_clang_format(${GF_EXE})

add_dependencies(
    ${GF_EXE}
    ${GF_EXE}_clangtidy
    run_clang_format
    run_cmake_format)
