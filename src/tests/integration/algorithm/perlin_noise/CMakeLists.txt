set(PERLINNOISE_EXEMPLE2D_EXE perlinnoiseexemple2d_exe)
set(PERLINNOISE_EXEMPLE2D_SRC PerlinNoiseExemple2D.cpp)

add_executable(${PERLINNOISE_EXEMPLE2D_EXE} PerlinNoiseExemple2D.cpp)

target_link_libraries(${PERLINNOISE_EXEMPLE2D_EXE} 
                      PRIVATE 
                      ${ALGORITHM_TEST_LIB})
                      
target_include_directories(${PERLINNOISE_EXEMPLE2D_EXE} 
                           PRIVATE 
                           ${CMAKE_SOURCE_DIR})