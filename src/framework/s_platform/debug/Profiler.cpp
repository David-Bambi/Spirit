#include <debug/Profiler.hpp>

#include <debug/Loggers.hpp>
#include <tsl/robin_map.h>

#include <execinfo.h>
#include <signal.h>

tsl::robin_set<const Traceable*> Profiler::Table = {};

void Profiler::Register(const Traceable* t)
{
    if (not Profiler::Table.contains(t))
        Profiler::Table.insert(t);
}

void Profiler::Register(Traceable* t, const std::deque<std::string>& tags)
{
    for (const std::string& tag : tags)
        t->AddTag(tag);

    if (not Profiler::Table.contains(t))
        Profiler::Table.insert(t);
}

void Profiler::Unregister(const Traceable* t)
{
    Profiler::Table.erase(t);
}

void Profiler::Unregister(Traceable* t, const std::deque<std::string>& tags)
{
    for (const std::string& tag : tags)
        t->RemoveTag(tag);

    if (t->_tags.empty())
        Profiler::Table.erase(t);
}

void Profiler::Trace(const std::string& tag, const Traceable* t)
{
    const bool IsRegister = Profiler::Table.contains(t);
    const bool IsTagged = t->TagExist(tag);
    
    if (IsRegister && IsTagged)
        Loggers::profile->info("{} : {}", tag, t->TraceStr());
}

void Profiler::TableDump()
{
    Loggers::profile->set_pattern("[%l] %v");

    for (const auto& t : Profiler::Table)
    {
        const void* TAddressStr = static_cast<const void*>(t);

        Loggers::profile->info("Adresse: {}, Type: {}", TAddressStr, t->Type());
    }
}

void Profiler::SummaryTableDump()
{
    Loggers::profile->set_pattern("[%l] %v");

    tsl::robin_map<std::string, std::vector<const Traceable*>> ObjByType = {};
    for (const auto& t : Profiler::Table)
    {
        ObjByType[t->Type()].push_back(t);
    }

    for (const auto& [type, objs] : ObjByType)
    {
        Loggers::profile->info("Type : {}, Count : {}, Memory {}", type, objs.size(),
                                                                    sizeof(*objs[0]) * objs.size());
    }
}
