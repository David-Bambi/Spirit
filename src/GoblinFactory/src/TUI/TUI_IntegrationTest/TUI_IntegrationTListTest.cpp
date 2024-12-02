#ifndef TUI_INTEGRATIONTLISTTEST_CPP
#define TUI_INTEGRATIONTLISTTEST_CPP

#include <string>

#include <TChoice/TChoiceList.hpp>
#include <TList/TList.hpp>

void TListEmptyConstructor();
void TListNameConstructor();
void TListNameListConstructor();
void TListAddInList();

void IntegrationTListTest()
{
    std::map<int, std::tuple<std::string ,std::function<void()>>> Choices;
    Choices[1] = {"TList empty", TListEmptyConstructor};
    Choices[2] = {"TList with name", TListNameConstructor};
    Choices[3] = {"TList with elements", TListNameListConstructor};
    Choices[4] = {"TList to add elements", TListAddInList};

    TChoiceList Tchl = TChoiceList(Choices);
    Tchl.Render();

    return;
}

void TListEmptyConstructor()
{
    TList<std::string>* TL = new TList<std::string>();
    TL->Render();

    return;
}

void TListNameConstructor()
{
    TList<std::string>* TL = new TList<std::string>("name");
    TL->Render();

    return;
}

void TListNameListConstructor()
{
    std::vector<std::string> StrVec = {"Test A", "Test B", "Test C"};
    TList<std::string>* TL = new TList<std::string>("Tests", StrVec);
    TL->Render();

    return;
}

void TListAddInList()
{
    std::string Str = "Test ajout";
    TList<std::string>* TL = new TList<std::string>("Liste pour l'ajout");
    TL->Render();

    TL->List().push_back(Str);
    TL->Render();
    return;
}



#endif