#include <camera/CameraBuilder.hpp>

CameraBuilder& CameraBuilder::GetInstance()
{
    return static_cast<CameraBuilder&>(Builder<Camera>::GetInstance());
}

CameraBuilder& CameraBuilder::WithPosition(glm::vec3 position)
{
    _obj->_pos = position;
    return *this;
}

CameraBuilder& CameraBuilder::WithFront(glm::vec3 front)
{
    _obj->_front = front;
    return *this;
}

CameraBuilder& CameraBuilder::Up(glm::vec3 up)
{
    _obj->_up = up;
    return *this;
}

CameraBuilder& CameraBuilder::WithUpdate(std::function<void(Camera&)> update)
{
    _obj->_update = update;
    return *this;
}

CameraBuilder& CameraBuilder::WithMouvementSettings(float sensitivity, float speed)
{
    _obj->_sensitivity = sensitivity;
    _obj->_speed = speed;
    return *this;
}

CameraBuilder& CameraBuilder::WithProjectionType(Projection_t type)
{
    _obj->_projectionType = type;
    return *this;
}

CameraBuilder& CameraBuilder::WithShader(unsigned int shaderid)
{
    _obj->_shaderId = shaderid;
    return *this;
}