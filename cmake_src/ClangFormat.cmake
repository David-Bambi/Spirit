
function(target_add_clang_format target_clangformat)
    
    find_package(Python3 COMPONENTS Interpreter)
    if(NOT ${Python_FOUND})
        return()
    endif() 

    file(GLOB_RECURSE CMAKE_FILES_CPP "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")
    file(GLOB_RECURSE CMAKE_FILES_HPP "${CMAKE_CURRENT_SOURCE_DIR}/*.hpp")
    
    set(CPP_FILES
        ${CMAKE_FILES_CPP}
        ${CMAKE_FILES_HPP})
    
    find_program(CLANGFORMAT clang-format)
    if(CLANGFORMAT)
        message(STATUS "Added Clang Format")
        add_custom_target(
            ${target_clangformat}
            COMMAND
                ${Python3_EXECUTABLE}
                ${CMAKE_SOURCE_DIR}/tools/run-clang-format.py ${CPP_FILES}
                --in-place
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            USES_TERMINAL)
    else()
        message(WARNING "CLANGFORMAT NOT FOUND")
    endif()
endfunction()