#ifndef TRACEABLE_HPP
#define TRACEABLE_HPP

#include <string>
#include <deque>
#include <tsl/robin_set.h>

class Traceable
{
  private:
    tsl::robin_set<std::string> _tags;
    void AddTag(const std::string& tag);
    void RemoveTag(const std::string& tag);
    bool TagExist(const std::string& tag) const;
    std::string Type() const;

  protected:
    Traceable();
    Traceable(const tsl::robin_set<std::string>& tags);
    Traceable(const Traceable& t);
    Traceable(Traceable&&) noexcept = default;
    Traceable& operator=(const Traceable&) = default;
    Traceable& operator=(Traceable&&) noexcept = default;
  
  public:
    virtual std::string TraceStr() const = 0;
    virtual ~Traceable();

    friend class Profiler;
    friend class Tracer;
};

#endif