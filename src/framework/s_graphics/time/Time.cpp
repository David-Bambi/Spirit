#include <time/Time.hpp>
#include <GLFW/glfw3.h>

float Time::deltatime = 0.0f;
float Time::lastframe = 0.0f;


void Time::Update()
{
float frame = static_cast<float>(glfwGetTime());
Time::deltatime = frame - Time::lastframe;
Time::lastframe = frame;
}