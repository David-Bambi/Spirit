#include <scene/Scene.hpp>

Scene::Scene()
{
  _renderer = Renderer::GetInstance();
}

void Scene::AddObject(const std::shared_ptr<SceneObject>& Obj)
{
    _objects.push_back(Obj);
    _renderer->AddObj(Obj);
}

void Scene::Render()
{
    _renderer->Render();
}