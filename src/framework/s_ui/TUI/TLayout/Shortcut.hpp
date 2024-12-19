#ifndef SHORTCUT_HPP
#define SHORTCUT_HPP

#include <iostream>
#include <string>

#define SHOW std::cout <<
#define ENDL  << std::endl;
#define BLANKL std::cout<<std::endl;
#define INDENT std::cout<<"   ";
#define ENDLIF(b) if (b) std::cout<<std::endl;
#define ASKIF(b, v) if (b) std::cin >> v;
#define ASK(v) std::getline(std::cin, v);


#endif