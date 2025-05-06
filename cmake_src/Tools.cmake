function(add_dependencies_if_exist target dependency)
    
if(TARGET ${target})
    add_dependencies(${target} ${dependency})
else()
    message(STATUS "Dependency ${dependency} is not added to ${target}.")
endif()

endfunction(add_dependencies_if_exist)
