#include <model/Model.hpp>

#include <component/Transform.hpp>


Model::Model()
{
    _components[std::type_index(typeid(Transform))] = 
        std::make_shared<Transform>(Transform());
}

Model::~Model()
{
}

void Model::ProcessComponents()
{
    get<Transform>()->Process();
}

void Model::SetUpdate(Update update)
{
    _Update = update;
}

void Model::Render()
{
    if (_Update)
    {
        _Update(*this);
        ProcessComponents();
    }

    for (const auto& Mesh : _meshes)
    {
        Mesh->Transform(get<Transform>()->Mat());
        Mesh->Render();
    }
  
}