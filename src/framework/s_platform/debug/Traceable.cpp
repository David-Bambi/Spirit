#include <debug/Traceable.hpp>

#include <debug/Profiler.hpp>
#include <string>
#include <typeindex>

Traceable::Traceable() : _tags({})
{
    Profiler::Register(this);
}

Traceable::Traceable(const Traceable& t) : _tags({})
{
    if (this == &t)
        return;

    Profiler::Register(this);
}

Traceable::~Traceable()
{
    Profiler::Unregister(this);
}

void Traceable::AddTag(const std::string& tag)
{
    if (not TagExist(tag))
        _tags.insert(tag);
}

void Traceable::RemoveTag(const std::string& tag)
{
    if (TagExist(tag))
        _tags.erase(tag);
}

bool Traceable::TagExist(const std::string& tag) const
{
    return _tags.contains(tag);
}

std::string Traceable::Type() const
{
    return typeid(*this).name();
}