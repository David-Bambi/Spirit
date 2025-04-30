set(MULTIPLETEXTURES_I_TEST_EXE multipletexturesitestexe)
set(MULTIPLETEXTURES_I_TEST_NAME sgraphic_texturemultiple)
set(MULTIPLETEXTURES_I_TEST_SRC MultipleTexturesITests.cpp)

file(COPY shader DESTINATION ".")
file(COPY texture DESTINATION ".")

add_executable(${MULTIPLETEXTURES_I_TEST_EXE} MultipleTexturesITests.cpp)

target_link_libraries(${MULTIPLETEXTURES_I_TEST_EXE}
                      PRIVATE ${GRAPHICI_TEST_LIB})

target_include_directories(${MULTIPLETEXTURES_I_TEST_EXE}
                           PRIVATE ${GRAPHICI_TEST_LIB})

add_test(NAME ${MULTIPLETEXTURES_I_TEST_NAME}
         COMMAND ${MULTIPLETEXTURES_I_TEST_EXE})
