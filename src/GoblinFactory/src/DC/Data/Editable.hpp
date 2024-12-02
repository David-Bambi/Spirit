#ifndef EDITABLE.HPP
#define EDITABLE_HPP

class Editable
{   
    private :
        std::map<int, std::function<void()> _settermember;
        std::map<int, std::variant<int,float,double,char,std::string> _editablemember;
};

#endif