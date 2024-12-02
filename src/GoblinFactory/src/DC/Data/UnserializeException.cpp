#include <Data/UnserializeException.hpp>

 UnserializeException::UnserializeException(const char* message)
 : std::exception(message) 
{}