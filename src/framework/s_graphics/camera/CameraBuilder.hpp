#ifndef CAMERABUILDER_HPP
#define CAMERABUILDER_HPP

#include <camera/Camera.hpp>
#include <builder/Builder.hpp>
#include <memory>
#include <camera/Camera.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <functional>
#include <camera/ProjectionDef.hpp>

/**
 * @brief Helper class to build mesh
 * 
 */
class CameraBuilder : public Builder<Camera>
{
    public : 
    CameraBuilder& WithUpdate(std::function<void(Camera&)> update);
    CameraBuilder& WithFront(glm::vec3 front);
    CameraBuilder& Up(glm::vec3 up);
    CameraBuilder& WithPosition(glm::vec3 position);
    CameraBuilder& WithShader(unsigned int shaderid);
    CameraBuilder& WithMouvementSettings(float sensitivity, float speed);
    CameraBuilder& WithProjectionType(Projection_t type);

    static CameraBuilder& GetInstance();
};

#endif