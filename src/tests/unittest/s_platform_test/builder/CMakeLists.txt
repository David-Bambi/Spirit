set(BUILDER_TEST_EXE buildertest)
set(BUILDER_TEST_NAME splatform_buildertest)
set(BUILDER_TEST_EXTERNAL_LIB s_platform Catch2::Catch2WithMain)
set(BUILDER_TEST_SRC buildertest.cpp)        

add_executable(${BUILDER_TEST_EXE} ${BUILDER_TEST_SRC})

target_link_libraries(${BUILDER_TEST_EXE} PRIVATE
                      ${BUILDER_TEST_EXTERNAL_LIB})
                      

add_test(NAME ${BUILDER_TEST_NAME} 
         COMMAND ${BUILDER_TEST_EXE})