#ifndef GRAPHICOBJECT_HPP
#define GRAPHICOBJECT_HPP

#include <object/Object.hpp>
#include <debug/Traceable.hpp>
#include <gobject/UGID.hpp>
#include <string>

class GraphicObject : public Object, public Traceable
{
  public:
    GraphicObject();
    GraphicObject(const GraphicObject& obj);
    virtual ~GraphicObject();

    void SetGID();
    void SetGID(const std::string& name);
    std::string Name() const;
    GID_t GID() const;

    std::string TraceStr() const override;

  protected:
    GID_t _gid;
    std::string _name;
};

#endif