#include <model/ModelBuilder.hpp>


ModelBuilder& ModelBuilder::GetInstance()
{
    return static_cast<ModelBuilder&>(Builder<Model>::GetInstance());
}

/**
 * @brief Add a mesh to the model
 * 
 * @param Path 
 * @return ModelBuilder& 
 */
ModelBuilder& ModelBuilder::WithMesh(std::unique_ptr<Mesh> mesh)
{
    _obj->_meshes.push_back(std::move(mesh));
    return *this;
}

/**
 * @brief Add a compoenent to the model
 * 
 * @param Path 
 * @return ModelBuilder& 
 */
ModelBuilder& ModelBuilder::WithPosition(glm::vec3 pos)
{
    _obj->get<Transform>()->Translate(pos);
    return *this;
}


ModelBuilder& ModelBuilder::WithRotation(glm::vec3 rot)
{    
    _obj->get<Transform>()->Rotate(rot);
    return *this;
}

ModelBuilder& ModelBuilder::WithScale(glm::vec3 sca)
{    
    _obj->get<Transform>()->Scale(sca);
    return *this;
}

ModelBuilder& ModelBuilder::WithUpdate(std::function<void(Model&)> update)
{    
    _obj->_Update = update;
    return *this;
}


