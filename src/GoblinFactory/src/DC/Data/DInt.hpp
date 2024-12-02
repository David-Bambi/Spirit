#ifndef DINT_HPP
#define DINT_HPP

#include <Data/DataType.hpp>
#include <Data/Displayable.hpp>
#include <Data/Serializable.hpp>
#include <Data/Comparable.hpp>
#include <Data/Editable.hpp>

class DInt : public Serializable,
             public Displayable,
             public Comparable<DInt>
             public Editable
{
    private :
        int _integer;
        
    public : 
        DInt(int integer = 0);

        int Integer();

        virtual void Display(ostream& os);
        virtual void Serialize(std::ofstream& ofs) const ;
        virtual void Unserialize(std::ifstream& ifs);
        virtual int CompareTo(const DInt& other) const;

        DataType Type();  
};

#endif