cmake_minimum_required(VERSION 3.10)

set(Spirit spirit_project)

set(MAJOR_VERSION 1)
set(MINOR_VERSION 0)

project(${Spirit} VERSION ${MAJOR_VERSION}.${MINOR_VERSION})

add_compile_definitions($<$<CONFIG:Debug>:DEBUG>)

# Module cmake
set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake_src/")

# Built in cmakes options
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(CmkOptions)

# Warning
include(Warnings)

# Clang Tidy
include(ClangTidy)

# Clang format
include(ClangFormat)

# Cmake format
include(CmakeFormat)
add_cmake_format()

# Sanitizer

include(Sanitizer)
if(SANITIZER_OPT)
    add_sanitizer_flags(TRUE TRUE)
endif()

# LTO
include(LTO)

# Documentation
include(docs)

# Tools
include(Tools)

# Ajouter les libraries externes
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
include(CPM)
cpmaddpackage("gh:catchorg/Catch2@3.8.1")
cpmaddpackage("gh:gabime/spdlog@1.15.2")
cpmaddpackage("gh:fmtlib/fmt#11.1.4")
cpmaddpackage("gh:jarro2783/cxxopts@3.2.0")
cpmaddpackage("gh:tessil/robin-map@1.4.0")
cpmaddpackage("gh:nlohmann/json@3.12.0")

# Chemin d'accès importantes pour la compilation du projet
set(EXTERNAL_LIB_DIR ${CMAKE_SOURCE_DIR}/external)
set(DOC_DIR ${CMAKE_SOURCE_DIR}/docs)

include(CTest)
enable_testing()

add_subdirectory(external)
add_subdirectory(src)
