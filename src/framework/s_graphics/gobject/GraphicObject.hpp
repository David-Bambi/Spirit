#ifndef GRAPHICOBJECT_HPP
#define GRAPHICOBJECT_HPP

#include <object/Object.hpp>
#include <debug/Traceable.hpp>

class GraphicObject : public Object, public Traceable
{
  public:
    GraphicObject();
};

#endif