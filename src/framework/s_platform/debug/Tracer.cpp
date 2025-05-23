#include <debug/Tracer.hpp>

#include <memory>
#include <spdlog/spdlog.h>
#include <iostream>

void Tracer::Trace(const Object& obj) 
{
    spdlog::get("trace")->info(obj.TraceInfo());
}

void Tracer::Trace(const char* message) 
{
    spdlog::get("trace")->info(message);
}

