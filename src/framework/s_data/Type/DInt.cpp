#include <Data/DInt.hpp>

#include <iostream>
#include <string>

#include <Data/DataType.hpp>
#include <Data/UnserializeException.hpp>

DInt::DInt(int integer)
{
    _integer = integer;
}

int DInt::Integer()
{
    return _integer;
}

void DInt::Display(std::ostream& os)
{
    os << std::to_string(_integer);
}

void DInt::Serialize(std::ofstream& ofs) const
{
    ofs << "DINT:" << std::to_string(_integer);
}

void DInt::Unserialize(std::ifstream& ifs) 
{

    std::string type;
    std::getline(ifs, type, ':');

    if (type != "DINT")
        throw UnserializeException(("We try to unserialize \"" + type + "\" to a DINT.").c_str());

    std::string IntStr;
    ifs >> IntStr;
    _integer = std::stoi(IntStr);
} 

DataType DInt::Type()
{
    return DataType::DINT;
} 

int DInt::CompareTo(const DInt& other) const
{
    return _integer - other._integer;
}