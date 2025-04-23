#ifndef SCENEOBJECT_HPP
#define SCENEOBJECT_HPP

#include <vector>

#include <scene/Renderable.hpp>

#include <model/Model.hpp>

class SceneObject : public Renderable
{
private :
    Model* _model; 

public:
    virtual const int InstanceId()=0;
    virtual const std::vector<float> Vertex()=0;
    virtual void Render()=0;
};

#endif