#ifndef DISPLAYABLE_HPP
#define DISPLAYABLE_HPP

#include <iostream>

using namespace std;

class Displayable
{
    public :
        virtual void Display(ostream& os)=0;

        friend ostream& operator << (ostream& os, Displayable& data);
};

#endif