set(CAMERASMOVEMENT_I_TEST_EXE cameramovementitestexe)
set(CAMERASMOVEMENT_I_TEST_NAME sgraphic_cameramovement)
set(CAMERASMOVEMENT_I_TEST_SRC CameraMovementITest.cpp)

file(COPY shader DESTINATION ".")

add_executable(${CAMERASMOVEMENT_I_TEST_EXE} CameraMovementITest.cpp)

target_link_libraries(${CAMERASMOVEMENT_I_TEST_EXE} 
                      PRIVATE 
                      ${GRAPHICI_TEST_LIB})
                      
target_include_directories(${CAMERASMOVEMENT_I_TEST_EXE} 
                           PRIVATE 
                           ${GRAPHICI_TEST_INC})

add_test(NAME ${CAMERASMOVEMENT_I_TEST_NAME} 
         COMMAND ${CAMERASMOVEMENT_I_TEST_EXE})