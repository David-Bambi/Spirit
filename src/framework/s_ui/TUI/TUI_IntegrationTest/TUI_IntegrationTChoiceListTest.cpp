#ifndef TUI_INTEGRATIONTCHOICELISTTEST_CPP
#define TUI_INTEGRATIONTCHOICELISTTEST_CPP

#include <string>

#include <TChoice/TChoiceList.hpp>
#include <TLayout/Shortcut.hpp>

void TChoiceListEmpty();
void TChoiceListSimple();

void IntegrationTChoiceListTest()
{
    TChoiceListEmpty();
    TChoiceListSimple();
    return;
}

void TChoiceListEmpty()
{
    TChoiceList Tchl = TChoiceList();
    Tchl.Render();
    return;
}

void TChoiceListSimple()
{
    std::map<int, std::tuple<std::string ,std::function<void()>>> Choices;
    Choices[1] = std::tuple<std::string ,std::function<void()>>("Execute Test A", []() {SHOW "Test A" ENDL; });
    Choices[2] = std::tuple<std::string ,std::function<void()>>("Execute Test B", []() {SHOW "Test B" ENDL; });
    Choices[3] = std::tuple<std::string ,std::function<void()>>("Execute Test C", []() {SHOW "Test C" ENDL; });

    TChoiceList Tchl = TChoiceList(Choices);
    Tchl.Render();
    return;
}


#endif