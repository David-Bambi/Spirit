#include <debug/Tracer.hpp>

#include <spdlog/spdlog.h>

void Tracer::Trace(const Traceable& t)
{
    spdlog::get("trace")->info(t.TraceStr());
}

void Tracer::Trace(const char* message)
{
    spdlog::get("trace")->info(message);
}

void Tracer::Trace(const std::string& message)
{
    spdlog::get("trace")->info(message);
}
