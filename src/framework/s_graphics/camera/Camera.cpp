#include <camera/Camera.hpp>
#include <camera/ProjectionDef.hpp>
#include <glad/glad.h>
#include <iostream>
#include <time/Time.hpp>
#include <uglfw/uglfw.hpp>
#include <gapp/Gapp.hpp>

void Camera::Update(unsigned int progshader)
{
    if (_update)
    {
        _update(*this);
    }
    _view = glm::lookAt(_pos, _pos + _front, _up);
    const auto screenWidth = static_cast<float>(Gapp::CurrentGapp->GetAppSetting().SCREEN_WIDTH);
    const auto screenHeight = static_cast<float>(Gapp::CurrentGapp->GetAppSetting().SCREEN_HEIGHT);

    if (_projectionType == Projection_t::PERSPECTIVE)
        _projection = glm::perspective(glm::radians(_fov), screenWidth / screenHeight, _near, _far);

    glUniformMatrix4fv(glGetUniformLocation(progshader, "view"), 1, GL_FALSE,
                       glm::value_ptr(_view));
    glUniformMatrix4fv(glGetUniformLocation(progshader, "projection"), 1, GL_FALSE,
                       glm::value_ptr(_projection));
}

void Camera::MoveForward()
{
    const float velocity = Time::deltatime * _speed;
    _pos += _front * velocity;
}

void Camera::MoveBackward()
{
    const float velocity = Time::deltatime * _speed;
    _pos -= _front * velocity;
}

void Camera::MoveLeft()
{
    const float speed = Time::deltatime * _speed;
    _pos -= _right * speed;
}

void Camera::MoveRight()
{
    const float speed = Time::deltatime * _speed;
    _pos += _right * speed;
}

void Camera::MoveUp()
{
    const float speed = Time::deltatime * _speed;
    _pos += _up * speed;
}

void Camera::MoveDown()
{
    const float speed = Time::deltatime * _speed;
    _pos -= _up * speed;
}

void Camera::Zoom(float yoffset)
{
    _fov -= yoffset;
    if (_fov < 1.0f)
        _fov = 1.0f;
    if (_fov > 45.0f)
        _fov = 45.0f;
}

void Camera::MouseMovement(float xoffset, float yoffset)
{
    _yaw += xoffset * _sensitivity;
    _pitch -= yoffset * _sensitivity;

    if (_pitch > 89.0f)
        _pitch = 89.0f;
    if (_pitch < -89.0f)
        _pitch = -89.0f;

    glm::vec3 front;
    front.x = (float) (cos(glm::radians(_yaw)) * cos(glm::radians(_pitch)));
    front.y = (float) (sin(glm::radians(_pitch)));
    front.z = (float) (sin(glm::radians(_yaw)) * cos(glm::radians(_pitch)));
    _front = glm::normalize(front);
    _right = Right();
    _up = Up();
}

glm::vec3 Camera::Right()
{
    return glm::normalize(glm::cross(_front, _worldup));
}

glm::vec3 Camera::Up()
{
    return glm::normalize(glm::cross(_right, _front));
}
