# Fonction pour générer un JAR avec un manifest
function(create_jar PROJECT_NAME FILES)

prepare_env(${PROJECT_NAME})

set(SRC_FILES)
set(CLASS_FILES)

foreach(FILE ${FILES})
    list(APPEND SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/${FILE}.java")
    list(APPEND CLASS_FILES "${CLASS_OUTPUT_DIR}/${FILE}.class")
endforeach() 

compile_java_source(${PROJECT_NAME} "${CLASS_FILES}" "${CLASS_OUTPUT_DIR}" "${SRC_FILES}")
generate_doc(${PROJECT_NAME} "${SRC_FILES}")


set(JAR_OUTPUT ${CMAKE_BINARY_DIR}/java/${PROJECT_NAME}/${PROJECT_NAME}.jar)

# Création du fichier JAR
add_custom_command(
    OUTPUT ${JAR_OUTPUT}
    COMMAND ${Java_JAR_EXECUTABLE} 
           --create  
           --file ${JAR_OUTPUT} 
           --manifest ${CMAKE_CURRENT_SOURCE_DIR}/MANIFEST.MF 
           -C ${CLASS_OUTPUT_DIR} 
           .
    DEPENDS ${CLASS_FILES}
    COMMENT "Creating JAR file"
)

# Cibles pour compilation et empaquetage
add_custom_target(CompileJava_${PROJECT_NAME} ALL DEPENDS ${CLASS_FILES})
add_custom_target(CreateJar_${PROJECT_NAME} ALL DEPENDS ${JAR_OUTPUT})

endfunction()

##########################################################################

function (create_test TEST_NAME FILES JUNIT)

prepare_env(${TEST_NAME})


set(SRC_FILES)
set(CLASS_FILES)

foreach(FILE ${FILES})
    list(APPEND SRC_FILES "${CMAKE_CURRENT_SOURCE_DIR}/${FILE}.java")
    list(APPEND CLASS_FILES "${CLASS_OUTPUT_DIR}/${FILE}.class")
endforeach() 

compile_java_source_with_classpath(${TEST_NAME} "${CLASS_FILES}" "${CLASS_OUTPUT_DIR}" "${SRC_FILES}" "${JUNIT}")

# Créer une cible pour compiler les fichiers Java
add_jar(${TEST_NAME}
    SOURCES ${SRC_FILES}
    INCLUDE_JARS ${JUNIT}
    OUTPUT_DIR ${TEST_DIR}
)

# Rajouter le test
add_test(
    NAME ${TEST_NAME}
    COMMAND java -jar ${JUNIT}
    --class-path ${CLASS_OUTPUT_DIR}
    --scan-classpath
)


endfunction()

##########################################################################
# PREPARE_ENV
##########################################################################
function (prepare_env PROJECT_NAME)

set(TEST_DIR_PRIV ${CMAKE_BINARY_DIR}/java/${PROJECT_NAME})
set(CLASS_OUTPUT_DIR_PRIV ${TEST_DIR_PRIV}/classes)

file(MAKE_DIRECTORY ${TEST_DIR_PRIV})
file(MAKE_DIRECTORY ${CLASS_OUTPUT_DIR_PRIV}) 

set(TEST_DIR ${TEST_DIR_PRIVATE} PARENT_SCOPE)
set(CLASS_OUTPUT_DIR ${CLASS_OUTPUT_DIR_PRIV} PARENT_SCOPE)

endfunction()

##########################################################################
# COMPILE_JAVA_SOURCE_WITH_CLASSPATH
##########################################################################
function (compile_java_source_with_classpath PROJECT_NAME CLASS_FILES CLASS_OUTPUT_DIR SRC_FILES CLASSPATH)

set(CMD ${Java_JAVAC_EXECUTABLE} -cp ${CLASSPATH} -d ${CLASS_OUTPUT_DIR} ${SRC_FILES})

add_custom_command(   
    OUTPUT ${CLASS_FILES}
    COMMAND ${CMD}
    DEPENDS ${SRC_FILES} 
    COMMENT "Compiling Java source files"
)
 
add_custom_target(Compile_${PROJECT_NAME} ALL DEPENDS ${CLASS_FILES})

endfunction()

##########################################################################
# COMPILE_JAVA_SOURCE
##########################################################################
function (compile_java_source PROJECT_NAME CLASS_FILES CLASS_OUTPUT_DIR SRC_FILES)

set(CMD ${Java_JAVAC_EXECUTABLE} -d ${CLASS_OUTPUT_DIR} ${SRC_FILES})

add_custom_command(   
    OUTPUT ${CLASS_FILES}
    COMMAND ${CMD}
    DEPENDS ${SRC_FILES} 
    COMMENT "Compiling Java source files"
)
 
add_custom_target(Compile_${PROJECT_NAME} ALL DEPENDS ${CLASS_FILES})

endfunction()

##########################################################################
# COMPILE_LIB_JAR
##########################################################################
function (create_lib_jar LIB_PATH CLASS_FILES CLASS_OUTPUT_DIR SRC_FILES CLASSPATH)

set(CMD ${Java_JAVAC_EXECUTABLE} -cp ${CLASSPATH} -d ${CLASS_OUTPUT_DIR} ${SRC_FILES})

add_custom_command(   
    OUTPUT ${CLASS_FILES}
    COMMAND ${CMD}
    DEPENDS ${SRC_FILES} 
    COMMENT "Compiling Java source files"
)
 
add_custom_target(Compile_${PROJECT_NAME} ALL DEPENDS ${CLASS_FILES})

endfunction()

##########################################################################
# GENERATE_DOC
##########################################################################
function (generate_doc PROJECT_NAME SRC_FILES)

set(DOC_DIR ${CMAKE_BINARY_DIR}/java/${PROJECT_NAME}/${PROJECT_NAME}_doc)
file(MAKE_DIRECTORY ${DOC_DIR})


add_custom_command(   
    OUTPUT ${DOC_DIR}/index.html
    COMMAND javadoc -d ${DOC_DIR} ${SRC_FILES} 
    DEPENDS ${SRC_FILES} 
    COMMENT "Compiling Java documentation"
)
 
# Cible personnalisée pour générer la documentation
add_custom_target(generate_docs ALL DEPENDS ${DOC_DIR}/index.html)
add_dependencies(Compile_${PROJECT_NAME} generate_docs)

endfunction()



##########################################################################
# ADD_EXTERNAL_JAR
##########################################################################
function (add_external_jar JAR_PATH)
FILE(COPY "${JAR_PATH}" DESTINATION "${CMAKE_BINARY_DIR}/lib/jar")
endfunction()