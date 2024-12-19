#ifndef TXTOTEXTFILESTRATEGY_TPP
#define TXTOTEXTFILESTRATEGY_TPP

#include <string>
#include <filesystem>
#include <fstream>

template <typename T>
TxToTextFileStrategy<T>::TxToTextFileStrategy(std::string directory,
                                              std::string filename,
                                              std::ios_base::openmode mode)
 : _directory(directory),
   _filename (filename),
   _mode(mode)
{}

template <typename T>
void TxToTextFileStrategy<T>::Save(std::set<T*> DataSet)
{
    if (!std::filesystem::exists(_directory))
        std::filesystem::create_directory(_directory);

    std::ofstream data_out;
    data_out.open((_directory + "/" + _filename).c_str(), _mode);

    for (T* Data : DataSet)
        data_out << *Data << std::endl;

    data_out.close();
}

template <typename T>
std::set<T*> TxToTextFileStrategy<T>::Load() 
{
std::set<T*> DataSet;

if (!std::filesystem::exists(_directory))
    return {};

std::ifstream data_in;
    data_in.open((_directory + "/" + _filename).c_str());

data_in >> std::ws;
while (!data_in.eof())
    {
    T* Data = new T();
    data_in >> *Data;
    DataSet.insert(Data);
    data_in >> std::ws;
    }
        
return DataSet;
}

#endif