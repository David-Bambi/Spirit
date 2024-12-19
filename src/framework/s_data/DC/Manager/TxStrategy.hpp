#ifndef TXTRATEGY_HPP
#define TXTRATEGY_HPP

#include <set>

template <typename T>
class TxStrategy
{
    public : 
        virtual void Save(std::set<T*> DataSet)=0;
        virtual std::set<T*> Load()=0;
};

#endif