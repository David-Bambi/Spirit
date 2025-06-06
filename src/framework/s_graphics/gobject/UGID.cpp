#include <gobject/UGID.hpp>

GID_t UGID::NextId = 0;
std::queue<GID_t> UGID::RecycleId = {};
tsl::robin_map <std::string, GID_t> UGID::Names = {};

GID_t UGID::Get()
{
    if (not RecycleId.empty())
    {
        GID_t ret = RecycleId.front();
        RecycleId.pop();
        return ret;
    }
    else
    {
        GID_t id = NextId++;
        return id;
    }
}

GID_t UGID::Get(std::string name)
{
    if (UGID::Names.contains(name))
        return UGID::Names[name];

    GID_t Ret = UGID::Get();
    UGID::Names[name] = Ret;
    return Ret;
}

void UGID::Free(GID_t id)
{
    UGID::RecycleId.push(id);
}

void UGID::Free(std::string name)
{
    if (UGID::Names.contains(name))
    {
        UGID::RecycleId.push(UGID::Names[name]);
        UGID::Names.erase(name);
    }
}

void UGID::Clear()
{
    UGID::RecycleId = {};
    UGID::Names = {};
    UGID::NextId = 0;
}