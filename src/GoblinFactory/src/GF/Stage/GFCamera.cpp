#include <GF/Stage/GFCamera.hpp>

GFCamera::GFCamera(unsigned int winWidth, unsigned int winHeight)
{
    this->_winWidth = winWidth;
    this->_winHeight = winHeight;

    this->_Pos = glm::vec3(0.0f, 0.0f, 3.0f);
    this->_Front = glm::vec3(0.0f, 0.0f, -1.0f);
    this->_Up = glm::vec3(0.0f, 1.0f, 0.0f);

    float windowWidthFloat = static_cast<float>(winWidth);
    float windowHeightFloat = static_cast<float>(winHeight);
   
    this->_lastX = windowWidthFloat/2.0f;
    this->_lastY = windowHeightFloat/2.0f;
    this->_isFirstMouse = true;

    this->_yaw = -90.0f;
    this->_pitch = 0;
    this->_fov = 45.0f;
    this->_speed = 24.0f;
}

void GFCamera::Turn(double xpos, double ypos)
{
    if (this->_isFirstMouse)
    {
        this->_lastX = xpos;
        this->_lastY = ypos;
        this->_isFirstMouse = false;
    }

    float xoffset = xpos - this->_lastX;
    float yoffset = this->_lastY - ypos;
    this->_lastX = xpos;
    this->_lastY = ypos;

    const float sensitivity = 0.1f;
    xoffset *= sensitivity;
    yoffset *= sensitivity;

    this->_yaw   += xoffset;
    this->_pitch += yoffset;  

    if(this->_pitch > 89.0f)
        this->_pitch =  89.0f;
    if(this->_pitch < -89.0f)
        this->_pitch = -89.0f;

    this->ModifyFront();
}

void GFCamera::MoveForward()
{
    this->_Pos += this->_Front * this->_speed;
}
void GFCamera::MoveBackward()
{
    this->_Pos -= this->_Front * this->_speed;
}
void GFCamera::MoveLeft()
{
    this->_Pos -= glm::normalize(glm::cross(this->_Front, this->_Up)) * this->_speed;
}
void GFCamera::MoveRight()
{
    this->_Pos += glm::normalize(glm::cross(this->_Front, this->_Up)) * this->_speed;
}

void GFCamera::ModifyFront()
{
    glm::vec3 direction;
    direction.x = cos(glm::radians(this->_yaw)) * cos(glm::radians(this->_pitch));
    direction.y = sin(glm::radians(this->_pitch));
    direction.z = sin(glm::radians(this->_yaw)) * cos(glm::radians(this->_pitch));
    this->_Front = glm::normalize(direction);
}

glm::mat4 GFCamera::ViewMatrix()
{
    return glm::lookAt(this->_Pos, 
                       this->_Pos + this->_Front, 
                       this->_Up); ;
}

glm::mat4 GFCamera::ProjectionMatrix()
{
    float winWidthFloat = static_cast<float>(this->_winWidth);
    float winHeightFloat = static_cast<float>(this->_winHeight);
    
    if (CameraType == Camera::Type::Othogonal)
        return glm::ortho(0.0f, winWidthFloat, 0.0f, winHeightFloat, this->_near, this->_far);
    else
        return glm::perspective(glm::radians(this->_fov), 
                                static_cast<float>(this->_winWidth) / static_cast<float>(this->_winHeight), 
                                this->_near, 
                                this->_far);
}