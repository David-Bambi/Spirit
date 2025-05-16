#ifndef PROFILER_HPP
#define PROFILER_HPP

#include <unordered_map>
#include <tsl/robin_map.h>
#include <deque>
#include <typeindex>
#include <object/Object.hpp>

class Profiler
{
public:
    struct ProfilingInfo
    {
        bool ActivateTracer = false;
    };

    static tsl::robin_map<const Object*, ProfilingInfo> Table;

    static void RegisterObject(const Object* obj, const ProfilingInfo& objinfo);
    static void UnregisterObject(const Object* obj, const ProfilingInfo& objinfo);
    static void TableDump();
};

#endif