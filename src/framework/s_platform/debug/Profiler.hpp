#ifndef PROFILER_HPP
#define PROFILER_HPP

#include <tsl/robin_map.h>
#include <tsl/robin_set.h>
#include <deque>
#include <typeindex>
#include <string>
#include <debug/Loggers.hpp>
#include <debug/Traceable.hpp>

class Profiler
{
  public:
    static tsl::robin_set<const Traceable*> Table;

    static void Register(const Traceable* t);
    static void Register(Traceable* t, const std::deque<std::string>& tags);
    static void Unregister(const Traceable* t);
    static void Unregister(Traceable* t, const std::deque<std::string>& tags);
    static void Trace(const std::string& tag, const Traceable* t);
    static void TableDump();
    static void SummaryTableDump();
};

#endif