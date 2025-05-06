#include <scene/SceneBuilder.hpp>

SceneBuilder& SceneBuilder::GetInstance()
{
    static SceneBuilder instance;
    return instance;
}

SceneBuilder& SceneBuilder::WithModel(std::unique_ptr<Model> model)
{
    _obj->_models.push_back(std::move(model));
    return *this;
}
