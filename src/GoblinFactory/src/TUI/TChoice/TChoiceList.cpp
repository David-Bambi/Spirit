#include <TChoice/TChoiceList.hpp>

#include <iostream>

#include <TLayout/Shortcut.hpp>
#include <TAskUser/TAskUser.hpp>

TChoiceList::TChoiceList()
    :   _choices({})
{}

TChoiceList::TChoiceList(std::map<int, std::tuple<std::string ,std::function<void()>>>& Choices)
    :   _choices(Choices)
{}


void TChoiceList::Render()
{

if (_choices.empty())
{ 
    SHOW "Aucune option disponible." ENDL;
    return;
}

TAskUser<int> UserInt = TAskUser<int>();

while (!UserInt.IsQuitting())
{
    SHOW "[Choice]" ENDL
    SHOW "Choisissez une option ci-dessous." ENDL
    BLANKL;

    for (const auto& ch : _choices)
    {
     INDENT SHOW ch.first << " : ";
     INDENT SHOW std::get<0>(ch.second) ENDL;
    }
    
    BLANKL;

    UserInt.Render();
    
    BLANKL;

    if (UserInt.IsQuitting())
        break;

    try {
        std::tuple<std::string ,std::function<void()>> UserCh = _choices.at(UserInt.UserInfo());
        
        if (std::get<1>(UserCh) != nullptr)
            std::get<1>(UserCh)();
        }
    catch (const std::out_of_range&)
        {
            SHOW "La saisie n'est pas une option valide." ENDL;
        }

    BLANKL;
}

}