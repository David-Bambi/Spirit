set(GROUNDCUBEMODEL_TEST_EXE groundcubemodelitestexe)
set(GROUNDCUBEMODEL_TEST_NAME sgraphic_groundcubemodel)
set(GROUNDCUBEMODEL_TEST_SRC GroundCubeModelITest.cpp)

file(COPY shader DESTINATION ".")

add_executable(${GROUNDCUBEMODEL_TEST_EXE} GroundCubeModelITest.cpp)

target_link_libraries(${GROUNDCUBEMODEL_TEST_EXE} PRIVATE ${GRAPHICI_TEST_LIB})

target_include_directories(${GROUNDCUBEMODEL_TEST_EXE}
                           PRIVATE ${GRAPHICI_TEST_INC})

add_test(NAME ${GROUNDCUBEMODEL_TEST_NAME} COMMAND ${GROUNDCUBEMODEL_TEST_EXE})
