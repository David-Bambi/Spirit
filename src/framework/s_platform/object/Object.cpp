#include <object/Object.hpp>

long int Object::NextSeqNo = 0;

Object::Object() : _seq_no(NextSeqNo++) {}

Object::Object(const Object& obj)
{
    if (this == &obj)
        return;

    _seq_no = NextSeqNo++;
}

Object::Object(Object&& obj) noexcept
{
    if (this == &obj)
        return;

    _seq_no = obj._seq_no;
    obj._seq_no = -1;
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

    _seq_no = obj._seq_no;
    obj._seq_no = -1;
    return *this;
}

Object::~Object()
{
    _seq_no = -1;
}

long int Object::SeqNo() const
{
    return _seq_no;
}