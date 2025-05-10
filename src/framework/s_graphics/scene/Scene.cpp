#include <scene/Scene.hpp>

void Scene::Init()
{
    _programShader->Init();

    if (_camera)
        _camera->Init(_programShader->Id());

    for (const auto& model : _models)
        model->Init(_programShader->Id());
}

void Scene::Render()
{
    _programShader->Use();
    _camera->Update();
    
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
