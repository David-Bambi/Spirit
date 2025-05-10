#include <scene/SceneBuilder.hpp>

SceneBuilder& SceneBuilder::GetInstance()
{
    static SceneBuilder instance;
    return instance;
}

SceneBuilder& SceneBuilder::WithModel(const std::shared_ptr<Model>& model)
{
    _obj->_models.push_back(model);
    return *this;
}

SceneBuilder& SceneBuilder::WithCamera(const std::shared_ptr<Camera>& camera)
{
    _obj->_camera = camera;
    return *this;
}

SceneBuilder& SceneBuilder::WithProgramShader(const std::shared_ptr<ProgramShader>& programShader)
{
    _obj->_programShader = programShader;
    return *this;
}