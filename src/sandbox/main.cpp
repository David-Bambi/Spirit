#include <iostream>

class Base {};

class DerivedA : public Base {
public:
     virtual void DisplayA() const {
                std::cout << "DisplayA" << std::endl;
     }
};

class DerivedB : public Base {
public:
    virtual void DisplayB() const {
                std::cout << "DisplayB" << std::endl;

    }   
};

void callPrint(const void* ptr) {

    const DerivedB* base = static_cast<const DerivedB*>(ptr);
    base->DisplayB();
}

int main() {

   Base* Base = new DerivedA();

   callPrint(Base); 

   delete Base;
   return 0;
}
