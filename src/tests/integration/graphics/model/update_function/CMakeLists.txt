set(UPDATE_FUNCTION_I_TEST_EXE updatefunctionitestexe)
set(UPDATE_FUNCTION_I_TEST_NAME sgraphic_updatefunction)
set(UPDATE_FUNCTION_I_TEST_SRC UpdateFunctionITests.cpp)

file(COPY shader DESTINATION ".")

add_executable(${UPDATE_FUNCTION_I_TEST_EXE} UpdateFunctionITests.cpp)

target_link_libraries(${UPDATE_FUNCTION_I_TEST_EXE}
                      PRIVATE ${GRAPHICI_TEST_LIB})

target_include_directories(${UPDATE_FUNCTION_I_TEST_EXE}
                           PRIVATE ${GRAPHICI_TEST_INC})

add_test(NAME ${UPDATE_FUNCTION_I_TEST_NAME}
         COMMAND ${UPDATE_FUNCTION_I_TEST_EXE})
