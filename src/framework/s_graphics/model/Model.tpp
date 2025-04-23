#ifndef MODEL_TPP
#define MODEL_TPP

#include <model/Model.hpp>

template <typename T>
std::shared_ptr<T> Model::get()
{
    auto it = _components.find(std::type_index(typeid(T)));
    if (it != _components.end()) 
    {
        return std::static_pointer_cast<T>(it->second);
    }
    return nullptr;
}

#endif