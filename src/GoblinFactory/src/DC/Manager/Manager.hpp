#ifndef MANAGER_HPP
#define MANAGER_HPP

#include <set>

#include <Manager/TxStrategy.hpp>

template <typename T>
class Manager
{
    private :
        std::set<T*> _dataset;
        TxStrategy<T>* _tx = nullptr;

    public :
        Manager();
        void SetTxStrategy(TxStrategy<T>& tx);
        std::set<T*>& DataSet();

        virtual void Save();
        virtual void Load();
};

#include <Manager/Manager.tpp>

#endif