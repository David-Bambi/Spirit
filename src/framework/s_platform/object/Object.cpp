#include <object/Object.hpp>

#include <debug/Profiler.hpp>

long int Object::NextSeqNo = 0;

Object::Object()
{
    _SeqNo = NextSeqNo++;

    #ifdef DEBUG
        Profiler::RegisterObject(this, {false});
    #endif
}

Object::Object(const Object& obj)
{
    if (this == &obj)
        return;

    _SeqNo = NextSeqNo++;

    #ifdef DEBUG
        Profiler::RegisterObject(this, {false});
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
        Profiler::UnregisterObject(this, {false});
    #endif

    _SeqNo = -1;
}

long int Object::SeqNo() const
{
    return _SeqNo;
}

std::type_index Object::Type() const
 { 
    return typeid(*this); 
}






