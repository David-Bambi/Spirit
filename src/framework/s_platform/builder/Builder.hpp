#ifndef BUILDER_HPP
#define BUILDER_HPP

#include <memory>
#include <iostream>
#include <debug/Tracer.hpp>

template <class T>
class Builder
{
  public:
    static Builder<T>& GetInstance();
    static void DeleteInstance();
    virtual T* Build();
    Builder<T>& WithTrace(std::deque<std::string> tags);

    virtual std::unique_ptr<T> BuildUnique();
    virtual std::shared_ptr<T> BuildShared();

  protected:
    Builder();
    virtual ~Builder() = default;
    Builder(const Builder&) = default;
    Builder(Builder&&) = default;
    Builder& operator=(const Builder&) = default;
    Builder& operator=(Builder&&) = default;

    std::unique_ptr<T> _obj = {};
    static Builder<T>* _instance;
};

#include <builder/Builder.tpp>

#endif