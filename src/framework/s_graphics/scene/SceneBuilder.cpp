#include <scene/SceneBuilder.hpp>

SceneBuilder& SceneBuilder::GetInstance()
{
    static SceneBuilder instance;
    return instance;
}

SceneBuilder& SceneBuilder::WithModel(const std::shared_ptr<Model>& model,
                                      const std::shared_ptr<ProgramShader>& programShader)
{
    _obj->_modelsByProgramShader[programShader].push_back(model);
    return *this;
}

SceneBuilder& SceneBuilder::WithCamera(const std::shared_ptr<Camera>& camera)
{
    _obj->_camera = camera;
    return *this;
}