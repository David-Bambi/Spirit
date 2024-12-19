#ifndef UNSERIALIZEEXCEPTION_HPP
#define UNSERIALIZEEXCEPTION_HPP

#include <iostream>
#include <stdexcept>

class UnserializeException : public std::exception
{
    public : 
        UnserializeException(const char* message);
};
#endif 