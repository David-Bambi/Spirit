#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <camera/ProjectionDef.hpp>
#include <functional>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <memory>
#include <object/Object.hpp>

class Camera : public Object
{
  public:
    using UpdateFct = std::function<void(Camera&)>;
    void Update(unsigned int progshader);

    void MoveForward();
    void MoveBackward();
    void MoveLeft();
    void MoveRight();
    void MoveUp();
    void MoveDown();
    void MouseMovement(float xoffset, float yoffset);
    void Zoom(float yoffset);

  private:
    Projection_t _projectionType = Projection_t::PERSPECTIVE;

    glm::vec3 _pos = {0.0f, 0.0f, 0.0f};
    glm::vec3 _front = {0.0f, 0.0f, -1.0f};
    glm::vec3 _up = {0.0f, 1.0f, 0.0f};
    glm::vec3 _right = {1.0f, 0.0f, 0.0f};
    glm::vec3 _worldup = {0.0f, 1.0f, 0.0f};

    glm::mat4 _view = glm::mat4(1.0f);
    glm::mat4 _projection = glm::mat4(1.0f);

    UpdateFct _update = nullptr;

    float _yaw = -90.0f;
    float _pitch = 0.0f;
    float _sensitivity = 0.1f;
    float _speed = 2.5f;
    float _zoom = 45.0f;
    float _fov = 45.0f;
    float _near = 0.1f;
    float _far = 100.0f;

    unsigned int _shaderId = 0;

    glm::vec3 Right();
    glm::vec3 Up();

    friend class CameraBuilder;
};

#endif