#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <string>

#include <Data/Serializable.hpp>
#include <Data/Displayable.hpp>

class Material : public Serializable,
                 public Displayable
{
    private :
        std::string _id;
        std::string _name;

    public :
        Material(); 
        Material(std::string Id, std::string Name);

        void Display(ostream& os);
        void Serialize(std::ofstream& ofs) const;
        void Unserialize(std::ifstream& ifs);

};

#endif