#include <ppm/ppm_f.hpp>

#include <fstream>
#include <ios>
#include <iostream>
#include <cstring>
#include <memory>

bool ppm_export (const char* filepath, const char* strtoexport)
{
std::fstream ppmfile;

try 
{
    ppmfile.open(filepath, std::ios::out | std::ios::trunc);
    ppmfile << strtoexport << '\0';
    ppmfile.close();
    return true;
}
catch (std::ios_base::failure& e)
{
    std::cout << e.what();
    ppmfile.close();
    return false;
}

}

bool ppm_import(const char* filepath, char*& outstr)
{
std::fstream ppmfile;

try 
{
    ppmfile.open(filepath, std::ios::in);

    ppmfile.seekg (0, ppmfile.end);
    int length = ppmfile.tellg();
    ppmfile.seekg (0, ppmfile.beg);

    outstr = new char[length + 1];

    ppmfile.get(outstr, length+1);
    outstr[length] = '\0';
    ppmfile.close();

    return true;    
}
catch (std::ios_base::failure& e)
{
    ppmfile.close();
    std::cout << e.what();
    return "";
}

}
