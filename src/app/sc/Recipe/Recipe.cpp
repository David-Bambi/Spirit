#include <Recipe/Recipe.hpp>

Recipe::Recipe(std::string Id, 
               std::string Name,
               std::deque<std::pair<Material, int>> Need,
               std::deque<std::pair<Material, int>> Provide,
               std::string Id_building,
               bool Baserecipe) :
    _id(Id),
    _name(Name),
    _need(Need),
    _provide(Provide),
    _id_building(Id_building),
    _baserecipe(Baserecipe)
    {}


const std::string Recipe::ToDataFile() const 
{
    // std::string Needs = "";
    // std::string Provides = "";

    // for (auto MatNeeded : _need)
    //     Needs += (MatNeeded.first.GetId() + ";" + std::to_string(MatNeeded.second) + ";");

    // for (auto MatProvide : _provide)
    //     Provides += (MatProvide.first.GetId() + ";"  + std::to_string(MatProvide.second) + ";");

    // return _id + ";" + _name + ";" + Needs 
    // + Provides + ";" + _id_building + ";" + std::to_string(_baserecipe);

    return "";;
}