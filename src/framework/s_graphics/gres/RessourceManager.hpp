#ifndef RESSOURCEMANAGER_HPP
#define RESSOURCEMANAGER_HPP

#include "gobject/UGID.hpp"
#include <gobject/GraphicObject.hpp>
#include <memory>
#include <singleton/Singleton.hpp>
#include <string>
#include <tsl/robin_map.h>

class RessourceManager : public Singleton<RessourceManager>
{
  public:
    void Clean();

    template <typename T>
    std::shared_ptr<T> get(GID_t gid);

    template <typename T>
    std::shared_ptr<T> get(std::string name);

  private:
    tsl::robin_map<GID_t, std::shared_ptr<GraphicObject>> _go = {};
};

#include <gres/RessourceManager.tpp>

#endif