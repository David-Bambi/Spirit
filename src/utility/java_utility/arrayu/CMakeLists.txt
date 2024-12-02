 
 set(MODULE ArrU)
 
 set(FILE_TO_COMPILE
     ArrU.java)

add_jar(ArrU ${FILE_TO_COMPILE})
     
#create_lib_jar(${MODULE} "${FILE_TO_COMPILE}")

# # Test
# set(FILE_TO_COMPILE_FOR_TESTS
#     array_utility/ArrUTests
#     array_utility/ArrU) 

# create_test(ArrUTests "${FILE_TO_COMPILE_FOR_TESTS}" ${JUNIT_JAR}) 

 