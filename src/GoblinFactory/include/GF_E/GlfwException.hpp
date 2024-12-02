#ifndef GLFW_EXCEPTION_HPP
#define GLFW_EXCEPTION_HPP

#include <exception>

struct FailedInitGladException : public std::exception
{
  const char * what () const throw ()
  {
      return "Failed to initialize GLAD";
  }
};

#endif
