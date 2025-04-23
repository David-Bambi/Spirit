# Fichier source et include pour la librarie
set(S_PLATFORM_LIB s_platform)

set(S_PLATFORM_SRC builder/Builder.cpp)

set(S_PLATFORM_INC ${CMAKE_CURRENT_SOURCE_DIR})

# Compilation de la librarie
add_library(${S_PLATFORM_LIB} SHARED ${S_PLATFORM_SRC})
target_include_directories(${S_PLATFORM_LIB} PUBLIC ${S_PLATFORM_INC})
