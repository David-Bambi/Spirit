#include <Data/Serializable.hpp>

ofstream& operator << (ofstream& ofs, const Serializable& data)
{
    data.Serialize(ofs);
    return ofs;    
}

ifstream& operator >> (ifstream& ifs, Serializable& data)
{
    try 
    {
        data.Unserialize(ifs); 
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception : " << e.what() << std::endl;
    }
  
    return ifs;
}