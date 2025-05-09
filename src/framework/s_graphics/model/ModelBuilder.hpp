#ifndef MODELBUILDER_HPP
#define MODELBUILDER_HPP

#include <builder/Builder.hpp>
#include <component/Component.hpp>
#include <component/Transform.hpp>
#include <functional>
#include <glm/glm.hpp>
#include <mesh/Mesh.hpp>
#include <model/Model.hpp>

/**
 * @brief Helper class to build model
 *
 */
class ModelBuilder : public Builder<Model>
{
  public:
    ModelBuilder& WithMesh(const std::shared_ptr<Mesh>& mesh);
    ModelBuilder& WithPosition(glm::vec3 pos);
    ModelBuilder& WithRotation(glm::vec3 rot);
    ModelBuilder& WithScale(glm::vec3 sca);
    ModelBuilder& WithUpdate(std::function<void(Model&)> update);

    static ModelBuilder& GetInstance();
};

#endif