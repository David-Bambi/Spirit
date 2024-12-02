#ifndef DSTR_HPP
#define DSTR_HPP

#include <string>

#include <Data/DataType.hpp>
#include <Data/Displayable.hpp>
#include <Data/Serializable.hpp>

class DStr : public Serializable,
             public Displayable
{
    private :
        std::string _string;
    public : 
        DStr(std::string str = "");

        std::string String();

        virtual void Display(ostream& os);
        virtual void Serialize(std::ofstream& ofs) const;
        virtual void Unserialize(std::ifstream& ifs);
        DataType Type();  
};

#endif