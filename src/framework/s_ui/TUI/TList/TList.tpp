#ifndef TLIST_TPP
#define TLIST_TPP

#include <iostream>
#include <string>

#include <TLayout/Shortcut.hpp>

template<typename T>
TList<T>::TList()
    :   _name(""),
        _list({})
{}

template<typename T>
TList<T>::TList(std::string Name)
    :   _name(Name),
        _list({})
{}

template<typename T>
TList<T>::TList(std::string Name, std::vector<T>& List) 
    :   _name(Name),
        _list(List)
      
{}

template<typename T>
std::vector<T>& TList<T>::List()
{
    return _list;
}

template<typename T>
void TList<T>::Render()
{
SHOW "[ " << "List - " << _name << " ]" ENDL;


for (T obj : _list)
{
    INDENT SHOW obj ENDL;
}
    
ENDLIF(_list.size()>0);

std::cout << "end of list ...";
BLANKL;
BLANKL;
}


#endif