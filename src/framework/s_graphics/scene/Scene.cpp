#include <scene/Scene.hpp>

void Scene::Init()
{
    _programShader->Init();

    for (const auto& model : _models)
        model->Init(_programShader->Id());
}

void Scene::Render()
{
    _programShader->Use();
    for (const auto& model : _models)
    {
        model->Render();
    }
}

void Scene::Clean()
{
    for (const auto& model : _models)
        model->Clean();
}
