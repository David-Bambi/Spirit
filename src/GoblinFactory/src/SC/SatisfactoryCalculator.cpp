#include <iostream>
#include <limits>
#include <Recipe/Recipe.hpp>
#include <Material/Material.hpp>
#include <Material/MaterialMgr.hpp>
#include <TChoice/TChoiceList.hpp>
#include <map>
#include <tuple>

void AddMaterial();
void ShowMaterialList();

int main ()
{
std::map<int, std::tuple<std::string ,std::function<void()>>> Choices;
Choices[1] = std::tuple<std::string ,std::function<void()>>("Add material", AddMaterial);
Choices[2] = std::tuple<std::string ,std::function<void()>>("Show material list", ShowMaterialList);

TChoiceList OperationChoice = TChoiceList(Choices);
OperationChoice.Render();

return 0;
}


void AddMaterial()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    char* Id = new char(10);
    std::cout << "Entrez l'identifiant : " ;  
    std::cin.getline(Id, 10);
    
    char* Name = new char(50);
    std::cout << "Entrez le nom : ";   
    std::cin.getline(Name, 50);
    
    std::cout << std::endl;
    MaterialMgr* MatMgr = MaterialMgr::GetInstance();
    const Material Mat = Material(Id, Name);
    
}

void ShowMaterialList()
{
    MaterialMgr* MatMgr = MaterialMgr::GetInstance();
    std::deque<Material> Materials;

    std::cout << std::endl << "Material list"  << std::endl << std::endl;

  
    std::cout << std::endl ;
}
