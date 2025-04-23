set(TRANSFORM_SCALE_I_TEST_EXE transformscaleitestexe)
set(TRANSFORM_SCALE_I_TEST_NAME sgraphic_transformscale)
set(TRANSFORM_SCALE_I_TEST_SRC TransformScaleITests.cpp)

file(COPY shader DESTINATION ".")

add_executable(${TRANSFORM_SCALE_I_TEST_EXE} TransformScaleITests.cpp)

target_link_libraries(${TRANSFORM_SCALE_I_TEST_EXE} 
                      PRIVATE 
                      ${GRAPHICI_TEST_LIB})
                      
target_include_directories(${TRANSFORM_SCALE_I_TEST_EXE} 
                           PRIVATE 
                           ${GRAPHICI_TEST_INC})

add_test(NAME ${TRANSFORM_SCALE_I_TEST_NAME} 
         COMMAND ${TRANSFORM_SCALE_I_TEST_EXE})