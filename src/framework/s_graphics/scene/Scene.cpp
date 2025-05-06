#include <scene/Scene.hpp>

void Scene::Render()
{
    for (const auto& model : _models)
    {
        model->Render();
    }
}
