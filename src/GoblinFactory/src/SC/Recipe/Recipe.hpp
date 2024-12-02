#ifndef RECIPE_HPP
#define RECIPE_HPP

#include <deque>
#include <string>

#include <Material/Material.hpp>

class Recipe 
{
    private :
        std::string _id;
        std::string _name;
        std::deque<std::pair<Material, int>> _need;
        std::deque<std::pair<Material, int>> _provide;
        std::string _id_building;
        bool _baserecipe;

    public :
        Recipe(std::string Id, 
               std::string Name,
               std::deque<std::pair<Material, int>> Need,
               std::deque<std::pair<Material, int>> Provide,
               std::string Id_building,
               bool Baserecipe);

        const std::string ToUI () const;
        const std::string ToDataFile() const;
};

#endif
