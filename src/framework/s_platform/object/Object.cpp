#include <object/Object.hpp>
#include <sstream>
#include <debug/Profiler.hpp>
#include <debug/Tracer.hpp>

long int Object::NextSeqNo = 0;

Object::Object()
{
    _SeqNo = NextSeqNo++;

    #ifdef DEBUG
        Profiler::RegisterObject(this);
    #endif
}

Object::Object(const Object& obj)
{
    if (this == &obj)
        return;

    _SeqNo = NextSeqNo++;

    #ifdef DEBUG
        Profiler::RegisterObject(this);
    #endif
}

Object::Object(Object&& obj) noexcept
{
    if (this == &obj)
        return;

    _SeqNo = obj._SeqNo;
    obj._SeqNo = -1;
}

Object& Object::operator=(const Object& obj)
{
    if (this == &obj)
        return *this;

    return *this;
}

Object& Object::operator=(Object&& obj) noexcept
{
    if (this == &obj)
        return *this;

    _SeqNo = obj._SeqNo;
    obj._SeqNo = -1;
    return *this;
}

Object::~Object()
{
    #ifdef DEBUG
        Profiler::UnregisterObject(this);
    #endif

    _SeqNo = -1;
}

long int Object::SeqNo() const
{
    return _SeqNo;
}

void Object::ActivateTrace(const std::deque<std::string>& Tags)
{
    for (auto& tag : Tags)
        _traces[tag] = true;;
}


std::string Object::TraceInfo() const
{
    std::ostringstream oss;
    oss << "Object: " << static_cast<const void*>(this) <<
           ", SeqNo: " << _SeqNo <<
           ", Type: " <<  typeid(*this).name();
    return oss.str();
}

std::type_index Object::Type() const
 { 
    return typeid(*this); 
}






