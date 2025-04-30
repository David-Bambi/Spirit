function(target_generate_docs target working_dir)

find_package(Doxygen)

if (DOXYGEN_FOUND)
    add_custom_target(
	    ${target}
	    ${DOXYGEN_EXECUTABLE}
	    WORKING_DIRECTORY ${working_dir}
    )
endif()

endfunction()


function(target_generate_uml target working_dir)

find_program(JAVA java)
if (JAVA)
	if (EXISTS ${CMAKE_SOURCE_DIR}/tools/plantuml-1.2025.2.jar)
		add_custom_target(
	        ${target}
	        COMMAND
	           java -jar ${CMAKE_SOURCE_DIR}/tools/plantuml-1.2025.2.jar -o ${working_dir} class_diagram.puml
	        WORKING_DIRECTORY ${working_dir}
		)
	else()
		message(WARNING "PlantUML not found")
	endif()
else()
	message(WARNING "Java not found")
endif()

endfunction()