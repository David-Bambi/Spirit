#ifndef TLIST_HPP
#define TLIST_HPP

#include <string>
#include <vector>
 
#include <TRendable/TRendable.hpp>

template<typename T>
class TList : public TRendable
{
private :
    std::string _name;
    std::vector<T> _list;

public :
    TList();
    TList(std::string Name);
    TList(std::string Name, std::vector<T>& List);

    std::vector<T>& List();
    virtual void Render();
};

#include <TList/TList.tpp>

#endif