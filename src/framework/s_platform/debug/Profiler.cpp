#include <debug/Profiler.hpp>

#include <spdlog/spdlog.h>
#include "spdlog/sinks/basic_file_sink.h"

tsl::robin_map<const Object*, Profiler::ProfilingInfo> Profiler::Table;


void Profiler::RegisterObject(const Object* obj, const ProfilingInfo& objinfo)
{
    Profiler::Table[obj] = objinfo;
}

void Profiler::UnregisterObject(const Object* obj, const ProfilingInfo& objinfo)
{
    Profiler::Table.erase(obj);
}

void Profiler::TableDump()
{
    auto logger = spdlog::basic_logger_mt("basic_logger", "logs");

    for (const auto& [obj, info] : Profiler::Table)
    {
        logger->info("Object: {}, SeqNo: {}, Type: {}", static_cast<const void*>(obj), obj->SeqNo(), obj->Type().name());
    }
}

