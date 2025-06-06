#ifndef GJSON_IMPORTER_HPP
#define GJSON_IMPORTER_HPP

#include <gapp/Gapp.hpp>
#include <memory>
#include <scene/Scene.hpp>
#include <string>

namespace GJsonImporter
{
    extern std::shared_ptr<Gapp> ImportGapp(std::string name);
    extern std::shared_ptr<Scene> ImportScene(std::string name);
}; 

#endif