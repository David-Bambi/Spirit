#include <gobject/GraphicObject.hpp>

#include <debug/Profiler.hpp>

GraphicObject::GraphicObject() : 
    Object(), 
    Traceable({"INIT", "RENDER", "CLEAN"}), 
    _gid(-1)
{
}

GraphicObject::GraphicObject(const GraphicObject& obj) : 
    Object(obj), 
    Traceable(obj), 
    _gid(-1)
{
}

GraphicObject::~GraphicObject()
{
    Profiler::Unregister(this);
    UGID::Free(_gid);
    _gid = -1;
}

void GraphicObject::SetGID()
{
    _gid = UGID::Get();
}

void GraphicObject::SetGID(const std::string& name)
{
    _name = name;
    _gid = UGID::Get(name);
}

std::string GraphicObject::TraceStr() const
{
    return "GraphicObject : " + std::to_string(_gid);
}

GID_t GraphicObject::GID() const
{
    return _gid;
}

std::string GraphicObject::Name() const
{
    return _name;
}