#include <model/Model.hpp>

#include <component/Transform.hpp>
#include <iostream>
#include <glm/glm.hpp>
Model::Model()
{
    _components[std::type_index(typeid(Transform))] = std::make_shared<Transform>(Transform());
}

void Model::Init(unsigned int progshader)
{
    for (const auto& mesh : _meshes)
        mesh->Init(progshader);
}

void Model::Clean()
{
    for (const auto& mesh : _meshes)
        mesh->Clean();
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