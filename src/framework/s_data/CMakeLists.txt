set(src_dc ${src_dc}
           Data/DInt.cpp
           Data/DStr.cpp
           Data/Serializable.cpp
           Data/UnserializeException.cpp
           Data/Displayable.cpp
           DataContext/DataContext.cpp
           Manager/Manager.tpp
           Manager/TxToTextFileStrategy.tpp
           Data/Comparable.tpp)

add_library(DC ${src_dc})
target_include_directories(DC PUBLIC ".")
set_target_properties(DC PROPERTIES CXX_STANDARD 23)
target_compile_options(DC PRIVATE /W3)

# Test unitaires
add_subdirectory(DC_UnitTest)
