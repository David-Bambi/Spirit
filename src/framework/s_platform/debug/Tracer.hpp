#ifndef TRACER_HPP
#define TRACER_HPP

#include <object/Object.hpp>
#include <spdlog/spdlog.h>
#include <debug/Loggers.hpp>


class Tracer
{
  public:
    Tracer() = default;
    Tracer(const Tracer&) = delete;
    Tracer(Tracer&&) = delete;
    Tracer& operator=(const Tracer&) = delete;
    Tracer& operator=(Tracer&&) = delete;
    ~Tracer() = default;

    static void Trace(const Object& obj);
    static void Trace(const char* message);
};

#endif 