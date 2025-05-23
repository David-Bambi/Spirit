#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <tsl/robin_map.h>
#include <string>
#include <deque>
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
    void ActivateTrace(const std::deque<std::string>& Tags);
    
  private:
    long int _SeqNo = 0;
    tsl::robin_map<std::string, bool> _traces;

    virtual std::string TraceInfo() const;

    friend class Tracer;
    friend class Profiler;
};


#endif