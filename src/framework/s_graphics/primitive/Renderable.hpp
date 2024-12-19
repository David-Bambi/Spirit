#ifndef RENDERABLE_HPP
#define RENDERABLE_HPP

class Renderable
{
public :
    virtual void Render() = 0;
    virtual ~Renderable() {}
};

#endif 