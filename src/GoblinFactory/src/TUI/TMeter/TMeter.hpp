#ifndef TMETER_HPP 
#define TMETER_HPP

#include <TRendable/TRendable.hpp>

#include <thread>

class TMeter : public TRendable
{
    private : 
        int _count;
        std::thread _thread;

    public : 
        TMeter();

        virtual void Render();

        void Start();
        void Stop();
};

#endif