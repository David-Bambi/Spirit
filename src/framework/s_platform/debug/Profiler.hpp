#ifndef PROFILER_HPP
#define PROFILER_HPP

#include <tsl/robin_map.h>
#include <tsl/robin_set.h>
#include <deque>
#include <typeindex>
#include <object/Object.hpp>
#include <string>
#include <debug/Loggers.hpp>

class Profiler 
{
public:

    static tsl::robin_set<const Object*> Table;
    static bool ActivateAll;

    static void RegisterObject(const Object* obj);
    static void UnregisterObject(const Object* obj);
    static void Profil(std::string Tag, const Object& obj);
    static void Trace(std::string tag, const Object& obj);
    static void TableDump();
    static void SummaryTableDump();

};

#endif