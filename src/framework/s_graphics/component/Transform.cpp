#include <component/Transform.hpp>

Transform::Transform()
    : _mat(glm::mat4(1.0f)), _pos(glm::vec3(0.0f, 0.0f, 0.0f)),
      _rot(glm::vec3(0.0f, 0.0f, 0.0f)), _sca(glm::vec3(1.0f, 1.0f, 1.0f)) {}

void Transform::Translate(glm::vec3 translate) { _pos = translate; }

void Transform::Rotate(glm::vec3 rotate) { _rot = rotate; }

void Transform::Scale(glm::vec3 scale) { _sca = scale; }

glm::mat4 Transform::Mat() { return _mat; }

void Transform::Process() {
  _mat = glm::translate(_mat, _pos);
  _mat = glm::rotate(_mat, glm::radians(_rot.x), glm::vec3(1.0f, 0.0f, 0.0f));
  _mat = glm::rotate(_mat, glm::radians(_rot.y), glm::vec3(0.0f, 1.0f, 0.0f));
  _mat = glm::rotate(_mat, glm::radians(_rot.z), glm::vec3(0.0f, 0.0f, 1.0f));
  _mat = glm::scale(_mat, _sca);
}