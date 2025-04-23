set(CAMERASTATIC_I_TEST_EXE camerastaticitestexe)
set(CAMERASTATIC_I_TEST_NAME sgraphic_camerastatic)
set(CAMERASTATIC_I_TEST_SRC CameraStaticITest.cpp)

file(COPY shader DESTINATION ".")

add_executable(${CAMERASTATIC_I_TEST_EXE} CameraStaticITest.cpp)

target_link_libraries(${CAMERASTATIC_I_TEST_EXE} 
                      PRIVATE 
                      ${GRAPHICI_TEST_LIB})
                      
target_include_directories(${CAMERASTATIC_I_TEST_EXE} 
                           PRIVATE 
                           ${GRAPHICI_TEST_INC})

add_test(NAME ${CAMERASTATIC_I_TEST_NAME} 
         COMMAND ${CAMERASTATIC_I_TEST_EXE})