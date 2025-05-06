#include <GLFW/glfw3.h>
#include <time/Time.hpp>

float Time::deltatime = 0.0f;
float Time::lastframe = 0.0f;

void Time::Update()
{
    const auto frame = static_cast<float>(glfwGetTime());
    Time::deltatime = frame - Time::lastframe;
    Time::lastframe = frame;
}