#ifndef READFILE_HPP
#define READFILE_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


std::string ReadFile(const char* filePath)
{
    std::string filestr;
    std::ifstream file;

    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        shaderFile.open(filePath);

        std::stringstream filestream;
        filestream << file.rdbuf();

        shaderFile.close();
        filestr = filestream.str();
    }
    catch (std::ifstream::failure& e)
    {
        std::cout << "ERROR::FILE_NOT_SUCCESFULLY_READ : " << filePath << "\n";
    }
    return filestr;
}

#endif