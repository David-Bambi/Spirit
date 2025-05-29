#include <singleton/Singleton.hpp>

template<class T>
std::unique_ptr<T> Singleton<T>::_instance = {};

template<class T>
T& Singleton<T>::Instance() 
{
    if (Singleton<T>::_instance == nullptr)
        Singleton<T>::_instance = std::make_unique<T>();

    return *Singleton<T>::_instance;
}