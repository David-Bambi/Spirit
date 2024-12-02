#ifndef TASKUSER_HPP
#define TASKUSER_HPP

#include <TRendable/TRendable.hpp>
#include <string>

template<typename T>
class TAskUser : public TRendable
{
private :
    std::string _message;
    T _userinfo;
    bool _isquitting = false;
    bool IsQuitting(std::string UserString);

public :
    TAskUser<T>();
    TAskUser(std::string Message);
    bool IsQuitting();

    virtual void Render();
    T UserInfo();
};

#endif;