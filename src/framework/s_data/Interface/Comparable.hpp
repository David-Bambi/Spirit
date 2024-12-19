#ifndef COMPARABLE_HPP
#define COMPARABLE_HPP

template <typename T>
class Comparable
{
    public :
        virtual int CompareTo(const T& other) const=0;

        bool operator<(const T& other) const;
        bool operator>(const T& other) const; 
        bool operator==(const T& other) const;
        bool operator<=(const T& other) const; 
        bool operator>=(const T& other) const; 
        bool operator!=(const T& other) const;  
};

#include <Data/Comparable.tpp>

#endif