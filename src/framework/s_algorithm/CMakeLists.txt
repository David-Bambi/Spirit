# Fichier source et include pour la librarie
set(S_ALGORITHM_LIB s_algorithm)
set(S_ALGORITHM_SRC algosrc/PerlinNoise.cpp algosrc/RandomNoise.cpp
                    algosrc/Normalize.cpp)
set(S_ALGORITHM_INC ${CMAKE_CURRENT_SOURCE_DIR})
set(S_ALGORITHM_LINK_LIB spdlog::spdlog)

# Compilation de la librarie
add_library(${S_ALGORITHM_LIB} STATIC ${S_ALGORITHM_SRC})

target_link_libraries(${S_ALGORITHM_LIB} PRIVATE ${S_ALGORITHM_LINK_LIB})

target_include_directories(${S_ALGORITHM_LIB} PUBLIC ${S_ALGORITHM_INC})
