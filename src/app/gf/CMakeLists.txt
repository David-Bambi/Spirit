set (GF_EXE gf.exe)

add_executable( ${GF_EXE} gf.cpp)

target_enable_lto(${GF_EXE} TRUE)
target_set_warnings(${GF_EXE} TRUE TRUE)
