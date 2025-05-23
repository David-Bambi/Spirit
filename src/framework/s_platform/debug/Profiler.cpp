#include <debug/Profiler.hpp>


tsl::robin_set<const Object*> Profiler::Table;
bool Profiler::ActivateAll = false;

void Profiler::RegisterObject(const Object* obj)
{
    Profiler::Table.insert(obj);
}

void Profiler::UnregisterObject(const Object* obj)
{
    Profiler::Table.erase(obj);
}

void Profiler::Profil(std::string Tag, const Object& obj)
{
    auto it = obj._traces.find(Tag);
    if (it != obj._traces.end() && it->second)
    spdlog::get("profiler")->info(obj.TraceInfo());
}

void Profiler::TableDump()
{
    spdlog::get("profiler")->set_pattern("[%l] %v");

    for (const auto& obj : Profiler::Table)
    {
        spdlog::get("profiler")->info("Object: {}, SeqNo: {}, Type: {}", static_cast<const void*>(obj), obj->SeqNo(), obj->Type().name());
    }
}

void Profiler::SummaryTableDump()
{
    spdlog::get("profiler")->set_pattern("[%l] %v");

    tsl::robin_map<const char*, std::vector<const Object*>> ObjByType = {};
    for (const auto& obj : Profiler::Table)
    {
        ObjByType[obj->Type().name()].push_back(obj);
    }

    for (const auto& [type, objs] : ObjByType) 
    {
        spdlog::get("profiler")->info("Type : {}, Count : {}, Memory {}", type, objs.size(), sizeof(*objs[0])*objs.size());
    }
}

void Profiler::Trace(std::string tag, const Object& obj)
{
    if (obj._traces.find(tag) != obj._traces.end() or Profiler::ActivateAll)
        spdlog::get("profiler")->info("{} : {}", tag, obj.TraceInfo());
}


