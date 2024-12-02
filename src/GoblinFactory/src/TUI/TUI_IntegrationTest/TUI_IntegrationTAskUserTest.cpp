#ifndef TUI_INTEGRATIONTASKUSERTEST_CPP
#define TUI_INTEGRATIONTASKUSERTEST_CPP

#include <string>

#include <TLayout/Shortcut.hpp>
#include <TAskUser/TAskUser.hpp>
#include <TChoice/TChoiceList.hpp>


void TAskUserInteger();
void TAskUserString();
void TAskUserQuit();
void TAskUserChar();

void IntegrationTAskUserTest()
{
    std::map<int, std::tuple<std::string ,std::function<void()>>> Choices;
    Choices[1] = {"TAskUser for integer", TAskUserInteger};
    Choices[2] = {"TAskUser for string", TAskUserString};
    Choices[3] = {"TAskUser for char", TAskUserChar};
    Choices[4] = {"TAskUser to quit", TAskUserQuit};

    TChoiceList Tchl = TChoiceList(Choices);
    Tchl.Render();

    return;
}

void TAskUserInteger()
{
    TAskUser<int> A_int = TAskUser<int>();
    A_int.Render();
    SHOW "Votre nombre est : " << A_int.UserInfo() ENDL
    return;
}

void TAskUserString()
{
    TAskUser<std::string> A_str = TAskUser<std::string>();
    A_str.Render();
    SHOW "Votre string est : \"" << A_str.UserInfo() << "\"" ENDL
    return;
}

void TAskUserChar()
{
    TAskUser<char> A_ch = TAskUser<char>();
    A_ch.Render();
    SHOW "Votre caractère est : \'" << A_ch.UserInfo() << "\'" ENDL
    return;
}

void TAskUserQuit()
{
    TAskUser<char> A_quit = TAskUser<char>("Entrez 'q' pour quitter : ");
    A_quit.Render();
    if (A_quit.IsQuitting())
        SHOW "A quitté !" ENDL;
    return;
}

#endif