#ifndef TXTOTEXTFILESTRATEGY_HPP
#define TXTOTEXTFILESTRATEGY_HPP

#include <string>
#include <set>
#include <iostream>

#include <Manager/TxStrategy.hpp>

template <typename T>
class TxToTextFileStrategy : public TxStrategy<T>
{
    private :
        std::string _directory;
        std::string _filename;
        std::ios_base::openmode _mode;

    public :
        TxToTextFileStrategy(std::string directory,
                             std::string filename,
                             std::ios_base::openmode mode = std::ios_base::trunc);

        virtual void Save(std::set<T*> DataSet);
        virtual std::set<T*> Load();
};

#include <Manager/TxToTextFileStrategy.tpp>

#endif