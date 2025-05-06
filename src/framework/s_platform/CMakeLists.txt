set(S_PLATFORM_LIB s_platform)
set(S_PLATFORM_SRC builder/Builder.cpp)
set(S_PLATFORM_INC ${CMAKE_CURRENT_SOURCE_DIR})

add_library(${S_PLATFORM_LIB} SHARED ${S_PLATFORM_SRC})

target_include_directories(${S_PLATFORM_LIB} PUBLIC ${S_PLATFORM_INC})

# Set target options
if(LTO_OPT)
    target_enable_lto(${S_PLATFORM_LIB} TRUE)
endif()

if(WARNINGS_OPT)
    target_set_warnings(${S_PLATFORM_LIB} TRUE FALSE)
endif()

# Documentation target
if(DOCUMENTATION_OPT)
    set(S_PLATFORM_DOC s_plateform_doc)
    set(S_PLATFORM_DOC_PATH ${CMAKE_SOURCE_DIR}/docs/framework/s_platform)
    target_generate_docs(${S_PLATFORM_DOC} ${S_PLATFORM_DOC_PATH})

    add_dependencies_if_exist(${S_PLATFORM_LIB} ${S_PLATFORM_DOC})

    # UML target
    set(S_PLATFORM_UML s_platform_uml)
    set(S_PLATFORM_UML_PATH ${CMAKE_SOURCE_DIR}/docs/framework/s_platform/uml)
    target_generate_uml(${S_PLATFORM_UML} ${S_PLATFORM_UML_PATH})

    add_dependencies_if_exist(${S_PLATFORM_LIB} ${S_PLATFORM_UML})
endif()

# Clang-tidy target
if(CLANGTIDY_OPT)
    set(S_PLATFORM_CLANGTIDY s_platform_clangtidy)
    target_add_clang_tidy(${S_PLATFORM_CLANGTIDY} ${S_PLATFORM_LIB})

    add_dependencies_if_exist(${S_PLATFORM_LIB} ${S_PLATFORM_CLANGTIDY})
endif()

# Clang-format target
if(CLANGFORMAT_OPT)
    set(S_PLATFORM_CLANGFORMAT s_platform_clangformat)
    target_add_clang_format(${S_PLATFORM_CLANGFORMAT})

    if(TARGET ${S_PLATFORM_CLANGFORMAT})
        add_dependencies(${S_PLATFORM_LIB} ${S_PLATFORM_CLANGFORMAT})
    endif()
endif()
