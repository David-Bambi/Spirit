#include <gobject/GraphicObject.hpp>

#include <debug/Profiler.hpp>

GraphicObject::GraphicObject()
{
    Profiler::Register(this, {"INIT", "RENDER", "CLEAN"});
}