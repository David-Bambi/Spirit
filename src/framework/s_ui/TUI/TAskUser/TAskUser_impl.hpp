#ifndef TASKUSER_DEF_HPP
#define TASKUSER_DEF_HPP

#include <string>

#include <TAskUser/TAskUser.hpp>
#include <TLayout/Shortcut.hpp>


/* Model definition */

template<typename T>
TAskUser<T>::TAskUser()
    :   _message("Entrez un choix (q pour quitter) : ")
{}

template<typename T>
TAskUser<T>::TAskUser(std::string Message)
    :   _message(Message)
{}

template<typename T>
T TAskUser<T>::UserInfo()
{
return _userinfo;
}

template<typename T>
bool TAskUser<T>::IsQuitting()
{
return _isquitting;
}

template<typename T>
void TAskUser<T>::Render()
{
SHOW _message;
ASK(_userinfo)
if (IsQuitting(_userinfo))
    return;
}

template<typename T>
bool TAskUser<T>::IsQuitting(std::string UserString)
{
if (UserString.length() == 1 &&
    UserString=="q")
    {
        SHOW "Quit !" ENDL;
        _isquitting = true;
        return true;
    }
return false;
}

/* Explicit template */

// int 

template<>
TAskUser<int>::TAskUser()
    :   _message("Entrez un nombre (q pour quitter) : "),
        _userinfo(0)
{}

template<>
void TAskUser<int>::Render()
{
std::string userentry;

SHOW _message;
ASK(userentry);

if (IsQuitting(userentry))
    return;

try {
        _userinfo = std::stoi(userentry);
    }
catch (const std::invalid_argument&) 
    {
        SHOW "La saisie n'est pas un entier valide." ENDL;
    } 
catch (const std::out_of_range&) 
    {
        SHOW "La saisie est en dehors de la plage d'un entier valide." ENDL;
    }
}

// string

template<>
TAskUser<std::string>::TAskUser()
    :   _message("Entrez une chaine de caractere (q pour quitter) : "),
        _userinfo("")
{}

template<>
void TAskUser<std::string>::Render()
{
std::string userentry;

SHOW _message;
ASK(userentry);

if (IsQuitting(userentry))
    return;

_userinfo = userentry;
}

// char

template<>
TAskUser<char>::TAskUser()
    :   _message("Entrez un caractère (q pour quitter) : "),
        _userinfo('\0')
{}

template<>
void TAskUser<char>::Render()
{
std::string userentry;

SHOW _message;
ASK(userentry);

size_t StrLength = userentry.length();

if (IsQuitting(userentry))
    return;

try {
        if (StrLength > 1 || StrLength < 1)
            throw "Le caractère entré n'est pas valide.";
        else
            _userinfo = userentry.at(0);
    }
catch (const char* message)
    {
        SHOW "Exception attrapée : " << message ENDL ;
    }
}

#endif