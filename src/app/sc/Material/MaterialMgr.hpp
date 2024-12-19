#ifndef MATERIALMGR_HPP
#define MATERIALMGR_HPP

#include <deque>

#include <Manager/Manager.hpp>
#include <Material/Material.hpp>
#include <Data/Serializable.hpp>


class MaterialMgr : public Manager<Material>
{
    protected : 
        static MaterialMgr* _instance;
        MaterialMgr();

    public : 
        static MaterialMgr* GetInstance();
};



#endif