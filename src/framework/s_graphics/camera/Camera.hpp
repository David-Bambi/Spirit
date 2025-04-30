#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <camera/ProjectionDef.hpp>
#include <functional>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <memory>

class Camera {
public:
  Camera();
  ~Camera();

  using UpdateFct = std::function<void(Camera &)>;
  void Update();

  void MoveForward();
  void MoveBackward();
  void MoveLeft();
  void MoveRight();
  void MoveUp();
  void MoveDown();
  void MouseMovement(float xoffset, float yoffset);
  void Zoom(float yoffset);

private:
  Projection_t _projectionType;

  glm::vec3 _pos;
  glm::vec3 _front;
  glm::vec3 _up;
  glm::vec3 _right;
  glm::vec3 _worldup;

  glm::mat4 _view;
  glm::mat4 _projection;

  UpdateFct _update;

  float _yaw;
  float _pitch;
  float _sensitivity;
  float _speed;
  float _zoom;
  float _fov;
  float _near;
  float _far;

  unsigned int _shaderId;

  glm::vec3 Right();
  glm::vec3 Up();

  friend class CameraBuilder;
};

#endif