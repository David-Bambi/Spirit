set(WINDOW_I_TEST_EXE windowitestexe)
set(WINDOW_I_TEST_NAME sgraphic_uglfw_window)
set(WINDOW_I_TEST_SRC WindowITest.cpp)

add_executable(${WINDOW_I_TEST_EXE} WindowITest.cpp)

target_link_libraries(${WINDOW_I_TEST_EXE} 
                      PRIVATE 
                      ${GRAPHICI_TEST_LIB})
                      
target_include_directories(${WINDOW_I_TEST_EXE} 
                           PRIVATE 
                           ${GRAPHICI_TEST_INC})

add_test(NAME ${WINDOW_I_TEST_NAME} 
         COMMAND ${WINDOW_I_TEST_EXE})