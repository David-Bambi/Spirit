#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <debug/Tracer.hpp>
#include <unordered_map>
#include <typeindex>

class Object
{
  public:
    static long int NextSeqNo;

    Object();
    Object(const Object&);
    Object(Object&&) noexcept;
    virtual Object& operator=(const Object&);
    virtual Object& operator=(Object&&) noexcept;
    virtual ~Object();

    std::type_index Type() const;
    long int SeqNo() const;
  private:
    long int _SeqNo = 0;

    friend Tracer;
};


#endif