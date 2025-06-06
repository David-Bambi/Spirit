#include <gres/RessourceManager.hpp>

#include <scene/Scene.hpp>
#include <gimporter/GJsonImporter.hpp>

template <typename T>
std::shared_ptr<T> RessourceManager::get(GID_t gid)
{
    if (_go.contains(gid))
        return std::dynamic_pointer_cast<T>(_go[gid]);
    else
        return nullptr;
}

template <>
std::shared_ptr<Scene> RessourceManager::get(std::string name)
{
    GID_t gid = UGID::Get(name);
    if (_go.contains(gid))
        return std::dynamic_pointer_cast<Scene>(_go[gid]);
    else
        return GJsonImporter::ImportScene(name);
}