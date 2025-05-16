set(GF_EXE gf)

set(GF_SRC gf.cpp)

set(GF_EXTERNAL_LIB
    glad
    glfw
    stb_image_lib
    s_type
    s_platform
    s_graphics
    spdlog::spdlog)

set(GF_INC ${CMAKE_CURRENT_SOURCE_DIR})

# Create library target
add_executable(${GF_EXE} ${GF_SRC})

target_include_directories(${GF_EXE} PUBLIC ${GF_INC} ${EXTERNAL_LIB_DIR})

target_link_libraries(${GF_EXE} PRIVATE ${GF_EXTERNAL_LIB})

# Set target options
if(LTO_OPT)
    target_enable_lto(${GF_EXE} TRUE)
endif()

if(WARNINGS_OPT)
    target_set_warnings(${GF_EXE} TRUE FALSE)
endif()

# Documentation target
if(DOCUMENTATION_OPT)
    set(S_GRAPHICS_DOC gf_doc)
    set(S_GRAPHICS_DOC_PATH ${CMAKE_SOURCE_DIR}/docs/app/gf)
    target_generate_docs(${S_GRAPHICS_DOC} ${S_GRAPHICS_DOC_PATH})

    add_dependencies_if_exist(${GF_EXE} ${S_GRAPHICS_DOC})

    # UML target
    # set(S_GRAPHICS_UML gf_uml)
    # set(S_GRAPHICS_UML_PATH ${CMAKE_SOURCE_DIR}/docs/app/gf/uml)
    # target_generate_uml(${S_GRAPHICS_UML} ${S_GRAPHICS_UML_PATH})

    # add_dependencies_if_exist(${GF_EXE} ${S_GRAPHICS_UML})
endif()

# Clang-tidy target
if(CLANGTIDY_OPT)
    set(S_GRAPHICS_CLANGTIDY gf_clangtidy)
    target_add_clang_tidy(${S_GRAPHICS_CLANGTIDY} ${GF_EXE})

    add_dependencies_if_exist(${GF_EXE} ${S_GRAPHICS_CLANGTIDY})
endif()

# Clang-format target
if(CLANGFORMAT_OPT)
    set(S_GRAPHICS_CLANGFORMAT gf_clangformat)
    target_add_clang_format(${S_GRAPHICS_CLANGFORMAT})

    if(TARGET ${S_GRAPHICS_CLANGFORMAT})
        add_dependencies(${GF_EXE} ${S_GRAPHICS_CLANGFORMAT})
    endif()
endif()
