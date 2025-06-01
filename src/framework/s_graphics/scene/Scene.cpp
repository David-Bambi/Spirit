#include <scene/Scene.hpp>

#include <debug/Profiler.hpp>
#include <debug/Tracer.hpp>
#include <sstream>

void Scene::Init()
{
    for (const auto& [programShader, models] : _modelsByProgramShader)
    {
        programShader->Init();
        programShader->Use();
        for (const auto& model : models)
            model->Init(programShader->Id());
    }
}

void Scene::Render()
{
    for (const auto& [programShader, models] : _modelsByProgramShader)
    {
        programShader->Use();
        _camera->Update(programShader->Id());

        for (const auto& model : models)
            model->Render();
    }
}

void Scene::Clean()
{
    for (const auto& model : _models)
        model->Clean();
}
