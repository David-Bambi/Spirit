#ifndef SERIALIZABLE_HPP
#define SERIALIZABLE_HPP

#include<iostream>
#include<fstream>

using namespace std;

class Serializable 
{
    public : 
        virtual void Serialize(ofstream& ofs) const =0;
        virtual void Unserialize(std::ifstream& ifs)=0; 

        friend ofstream& operator << (ofstream& ofs, const Serializable& data);
        friend ifstream& operator >> (ifstream& ifs, Serializable& data);
};

#endif