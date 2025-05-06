#ifndef OBJECT_HPP
#define OBJECT_HPP

class Object
{
  public:
    Object() = default;
    Object(const Object&) = default;
    Object(Object&&) noexcept = default;
    Object& operator=(const Object&) = default;
    Object& operator=(Object&&) = default;
    virtual ~Object() = default;
};

#endif