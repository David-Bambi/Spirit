#ifndef TCHOICELIST_HPP
#define TCHOICELIST_HPP

#include <functional>
#include <map>
#include <string>
#include <tuple>

#include <TRendable/TRendable.hpp>

class TChoiceList : public TRendable
{
    private :
        std::map<int, std::tuple<std::string ,std::function<void()>>> _choices;

    public :
        TChoiceList();
        TChoiceList(std::map<int, std::tuple<std::string ,std::function<void()>>>& Choices);
        virtual void Render(); 
};

#endif