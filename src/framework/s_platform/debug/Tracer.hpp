#ifndef TRACER_HPP
#define TRACER_HPP

#include <debug/Loggers.hpp>
#include <debug/Traceable.hpp>

class Tracer
{
  public:
    Tracer() = default;
    Tracer(const Tracer&) = delete;
    Tracer(Tracer&&) = delete;
    Tracer& operator=(const Tracer&) = delete;
    Tracer& operator=(Tracer&&) = delete;
    ~Tracer() = default;

    static void Trace(const Traceable& obj);
    static void Trace(const char* message);
};

#endif