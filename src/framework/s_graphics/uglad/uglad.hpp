#ifndef UGLAD_HPP
#define UGLAD_HPP

#include <exception>

namespace uglad
{ 
    
struct FailedInitGladException : public std::exception
{
    const char * what () const throw ()
    {
        return "Failed to initialize GLAD";
    }
};

void GladInit();
}

#endif
