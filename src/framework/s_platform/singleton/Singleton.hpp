#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <memory>

template <class T>
class Singleton
{
  public:
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    static T& Instance();

  protected:
    static std::unique_ptr<T> _instance;

    Singleton() = default;
    virtual ~Singleton() = default;
};

#include <singleton/Singleton.tpp>

#endif