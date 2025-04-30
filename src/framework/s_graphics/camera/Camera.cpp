#include <appsetting/AppSetting.hpp>
#include <camera/Camera.hpp>
#include <camera/ProjectionDef.hpp>
#include <glad/glad.h>
#include <iostream>
#include <time/Time.hpp>
#include <uglfw/uglfw.hpp>

Camera::Camera()
    : _pos(glm::vec3(0.0f, 0.0f, 0.0f)), _front(glm::vec3(0.0f, 0.0f, -1.0f)),
      _worldup(glm::vec3(0.0f, 1.0f, 0.0f)), _projection(glm::mat4(1.0f)),
      _speed(2.5f), _sensitivity(0.1f), _yaw(-90.0f), _pitch(0.0f), _fov(45.0f),
      _near(0.1f), _far(100.0f) {}

Camera::~Camera() {}

void Camera::Update() {
  if (_update) {
    _update(*this);
  }
  _view = glm::lookAt(_pos, _pos + _front, _up);

  if (_projectionType == Projection_t::PERSPECTIVE)
    _projection = glm::perspective(
        glm::radians(_fov),
        AppSetting::SCREEN_WIDTH / AppSetting::SCREEN_HEIGHT, _near, _far);

  glUniformMatrix4fv(glGetUniformLocation(_shaderId, "view"), 1, GL_FALSE,
                     glm::value_ptr(_view));
  glUniformMatrix4fv(glGetUniformLocation(_shaderId, "projection"), 1, GL_FALSE,
                     glm::value_ptr(_projection));
}

void Camera::MoveForward() {

  float velocity = Time::deltatime * _speed;
  _pos += _front * velocity;
}

void Camera::MoveBackward() {
  float velocity = Time::deltatime * _speed;
  _pos -= _front * velocity;
}

void Camera::MoveLeft() {
  float speed = Time::deltatime * _speed;
  _pos -= _right * speed;
}

void Camera::MoveRight() {
  float speed = Time::deltatime * _speed;
  _pos += _right * speed;
}

void Camera::MoveUp() {
  float speed = Time::deltatime * _speed;
  _pos += _up * speed;
}

void Camera::MoveDown() {
  float speed = Time::deltatime * _speed;
  _pos -= _up * speed;
}

void Camera::Zoom(float yoffset) {
  _fov -= yoffset;
  if (_fov < 1.0f)
    _fov = 1.0f;
  if (_fov > 45.0f)
    _fov = 45.0f;
}

void Camera::MouseMovement(float xoffset, float yoffset) {
  _yaw += xoffset * _sensitivity;
  _pitch -= yoffset * _sensitivity;

  if (_pitch > 89.0f)
    _pitch = 89.0f;
  if (_pitch < -89.0f)
    _pitch = -89.0f;

  glm::vec3 front;
  front.x = cos(glm::radians(_yaw)) * cos(glm::radians(_pitch));
  front.y = sin(glm::radians(_pitch));
  front.z = sin(glm::radians(_yaw)) * cos(glm::radians(_pitch));
  _front = glm::normalize(front);
  _right = Right();
  _up = Up();
}

glm::vec3 Camera::Right() {
  return glm::normalize(glm::cross(_front, _worldup));
}

glm::vec3 Camera::Up() { return glm::normalize(glm::cross(_right, _front)); }
