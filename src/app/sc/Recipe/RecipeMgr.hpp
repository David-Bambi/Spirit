#ifndef RECIPEMGR_HPP
#define RECIPEMGR_HPP

#include <deque>

#include <Recipe/Recipe.hpp>

class RecipeMgr 
{
    private :
        std::deque<Recipe> Recipes;
};

#endif