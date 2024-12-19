#include <Material/Material.hpp>

Material::Material() :
    _id(""),
    _name("")
{}

Material::Material(std::string Id, std::string Name) :
    _id(Id),
    _name(Name)
{}

void Material::Display(ostream& os)
{
    os << _id << " : " << _name << std::endl;
}

void Material::Unserialize(std::ifstream& ifs) 
{

}

void Material::Serialize(std::ofstream& ofs) const
{

}
