#include <uglad/uglad.hpp>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void uglad::GladInit()
{   
try
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw FailedInitGladException();
}    
catch(FailedInitGladException& E)
{
    std::cout << E.what() << std::endl;
}
}