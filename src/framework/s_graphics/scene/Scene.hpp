#ifndef SCENE_HPP
#define SCENE_HPP

#include <memory>

#include <scene/SceneObject.hpp>
#include <scene/Renderer.hpp>


class Scene
{
private : 
    Renderer* _renderer;
    std::vector<std::shared_ptr<SceneObject>> _objects;
public :
    Scene();
    void AddObject(const std::shared_ptr<SceneObject>& Obj);
    void Render();
};

#endif