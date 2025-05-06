#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <component/Component.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Transform : public Component
{
  public:
    Transform();
    void Translate(glm::vec3 translate);
    void Rotate(glm::vec3 rotate);
    void Scale(glm::vec3 scale);
    void SetRotation(glm::vec3 rotation);

    glm::mat4 Mat();

    void Process() override;

  private:
    glm::mat4 _mat;
    glm::vec3 _pos;
    glm::vec3 _rot;
    glm::vec3 _sca;
};

#endif