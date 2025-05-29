#ifndef BUILDER_TPP
#define BUILDER_TPP

#include <builder/Builder.hpp>

template <class T>
Builder<T>* Builder<T>::_instance = nullptr;

template <class T>
Builder<T>::Builder()
{
    _obj  = std::make_unique<T>();
};

/**
 * @brief Get the unique instance of the Builder class.
 *
 * @return Builder*
 */
template <class T>
Builder<T>& Builder<T>::GetInstance()
{ 
    if (_instance == nullptr)
        _instance = new Builder<T>();
    return *_instance;
};

/**
 * @brief Clean the memory for the singleton instance of the Builder.
 */
template <class T>
void Builder<T>::DeleteInstance()
{
    delete _instance;
    _instance = nullptr;
}

 /**
  * @brief Build a object and reset the builder objet
  *
  */
template <class T>
T* Builder<T>::Build()
{
    T* obj = _obj.release();
    _obj = std::make_unique<T>();
    return obj;
} 

/**
 * @brief Build a unique ptr object and reset the builder objet
 *
 */
template <class T>
std::unique_ptr<T> Builder<T>::BuildUnique()
{
    std::unique_ptr<T> obj = std::make_unique<T>();
    obj.swap(_obj);
    return obj;
}

/**
 * @brief Build a shared ptr object and reset the builder objet
 *
 */
template <class T>
std::shared_ptr<T> Builder<T>::BuildShared()
{
    std::shared_ptr<T> obj = std::make_shared<T>(std::move(*_obj));
    _obj = std::make_unique<T>();
    return obj;
}

#endif