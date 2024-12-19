#include <Data/DStr.hpp>

#include <iostream>
#include <string>

#include <Data/DataType.hpp>
#include <Data/UnserializeException.hpp>

DStr::DStr(std::string string)
{
    _string = string;
}

std::string DStr::String()
{
    return _string;
}

void DStr::Display(std::ostream& os)
{
    os << _string;
}

void DStr::Serialize(std::ofstream& ofs) const
{
    ofs << "DSTR:" << _string;
}

void DStr::Unserialize(std::ifstream& ifs) 
{
    std::string type;
    std::getline(ifs, type, ':');

    if (type != "DSTR")
        throw UnserializeException(("We try to unserialize a " + type + " to a DSTR.").c_str());

    ifs >> _string;
} 

DataType DStr::Type()
{
    return DataType::DSTR;
} 
