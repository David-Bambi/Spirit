#ifndef TUI_INTEGRATIONTEST_CPP
#define TUI_INTEGRATIONTEST_CPP

#include <TChoice/TChoiceList.hpp>
#include <TLayout/Shortcut.hpp>

void IntegrationTListTest();
void IntegrationTAskUserTest();
void IntegrationTChoiceListTest();

int main ()
{
std::map<int, std::tuple<std::string ,std::function<void()>>> Choices;
Choices[1] = std::tuple<std::string ,std::function<void()>>("TList", IntegrationTListTest);
Choices[2] = std::tuple<std::string ,std::function<void()>>("TAskUser", IntegrationTAskUserTest);
Choices[3] = std::tuple<std::string ,std::function<void()>>("Tchoice", IntegrationTChoiceListTest);

TChoiceList Tchl = TChoiceList(Choices);
Tchl.Render();
}

#endif