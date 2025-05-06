#include <model/Model.hpp>

#include <component/Transform.hpp>

Model::Model()
{
    _components[std::type_index(typeid(Transform))] = std::make_shared<Transform>(Transform());
}

void Model::ProcessComponents()
{
    get<Transform>()->Process();
}

void Model::SetUpdate(Update update)
{
    _update = std::move(update);
}

void Model::Render()
{
    if (_update)
    {
        _update(*this);
        ProcessComponents();
    }

    for (const auto& Mesh : _meshes)
    {
        Mesh->Transform(get<Transform>()->Mat());
        Mesh->Render();
    }
}