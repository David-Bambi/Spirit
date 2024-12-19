#include <Data/Displayable.hpp>

ostream& operator << (ostream& os, Displayable& data)
{
    data.Display(os);
    return os;
}