set(TRANSFORM_TRANSLATE_I_TEST_EXE transformtranslateitestexe)
set(TRANSFORM_TRANSLATE_I_TEST_NAME sgraphic_transformtranslate)
set(TRANSFORM_TRANSLATE_I_TEST_SRC TransformTranslateITests.cpp)

file(COPY shader DESTINATION ".")

add_executable(${TRANSFORM_TRANSLATE_I_TEST_EXE} TransformTranslateITests.cpp)

target_link_libraries(${TRANSFORM_TRANSLATE_I_TEST_EXE} 
                      PRIVATE 
                      ${GRAPHICI_TEST_LIB})
                      
target_include_directories(${TRANSFORM_TRANSLATE_I_TEST_EXE} 
                           PRIVATE 
                           ${GRAPHICI_TEST_INC})

add_test(NAME ${TRANSFORM_TRANSLATE_I_TEST_NAME} 
         COMMAND ${TRANSFORM_TRANSLATE_I_TEST_EXE})