set(RANDOMNOISE_EXEMPLE_EXE randomnoiseexemple_exe)

add_executable(${RANDOMNOISE_EXEMPLE_EXE} RandomNoiseExemple.cpp)

target_link_libraries(${RANDOMNOISE_EXEMPLE_EXE} 
                      PRIVATE 
                      ${ALGORITHM_TEST_LIB})
                      
target_include_directories(${RANDOMNOISE_EXEMPLE_EXE} 
                           PRIVATE 
                           ${CMAKE_SOURCE_DIR})