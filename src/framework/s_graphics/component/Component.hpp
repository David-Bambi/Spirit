#ifndef COMPONENT_HPP
#define COMPONENT_HPP

class Component
{
  public:
    virtual void Process() = 0;
    virtual ~Component() = default;
    Component() = default;
    Component(const Component&) = default;
    Component(Component&&) = default;
    Component& operator=(const Component&) = default;
    Component& operator=(Component&&) = default;
};

#endif