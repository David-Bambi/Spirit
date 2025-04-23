#ifndef BUILDER_HPP
#define BUILDER_HPP

#include <memory>

template<class T>
class Builder
{
    public :
        /**
        * @brief Get the unique instance of the Builder class.
        * 
        * @return Builder* 
        */
        static Builder<T>& GetInstance()
        {
        if(_instance == nullptr)
            _instance = new Builder<T>();

        return *_instance;
        };

        /**
         * @brief Clean the memory for the singleton instance of the Builder.
         */
        static void DeleteInstance()
        {
            delete _instance;
            _instance = nullptr;
        }

        /**
         * @brief Build a object and reset the builder objet
         * 
         */
        std::unique_ptr<T> Build()
        {
            std::unique_ptr<T> obj = std::make_unique<T>();
            obj.swap(_obj);
            return obj;
        }

    protected :
        Builder<T>() : _obj(std::make_unique<T>()){};

        ~Builder()=default;

        std::unique_ptr<T> _obj;
        static Builder* _instance;

        Builder<T>(const Builder<T>&) = delete;
        Builder<T>& operator=(const Builder<T>&) = delete;

};

template <class T>
Builder<T>* Builder<T>::_instance = nullptr;

#endif