#ifndef MODELBUILDER_HPP
#define MODELBUILDER_HPP

#include <builder/Builder.hpp>
#include <model/Mesh.hpp>
#include <model/Model.hpp>
#include <component/Component.hpp>
#include <component/Transform.hpp>
#include <glm/glm.hpp>
#include <functional>

/**
 * @brief Helper class to build model
 * 
 */
class ModelBuilder : public Builder<Model>
{
    public : 
        ModelBuilder& WithMesh(std::unique_ptr<Mesh> mesh);       
        ModelBuilder& WithPosition(glm::vec3 pos);
        ModelBuilder& WithRotation(glm::vec3 rot);
        ModelBuilder& WithScale(glm::vec3 sca);
        ModelBuilder& WithUpdate(std::function<void(Model&)> update);

        static ModelBuilder& GetInstance();
};

#endif