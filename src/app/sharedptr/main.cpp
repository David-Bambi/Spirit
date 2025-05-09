#include <iostream>
#include <string>
#include <memory>

class Base 
{
public:
    int i = 0;
    virtual void Display() const {
        std::cout << "Base Display" << std::endl;
    }
};

class Base2
{
public:
    std::shared_ptr<Base> basePtr;
    void SetBasePtr(const std::shared_ptr<Base>& ptr) {
        basePtr = ptr;
        basePtr->i = 800;
    };
};

void DisplayBase (const std::shared_ptr<Base>& basePtr) {

    std::cout << basePtr.get() << std::endl;
    std::cout << basePtr.use_count() << std::endl;  
    basePtr->i = 1;
    basePtr->Display();
}


int main ()
{
    const std::shared_ptr<Base> basePtr = std::make_shared<Base>();

    std::shared_ptr<Base> basePtr2 = basePtr;
    basePtr2->i = 100;

    std::shared_ptr<Base2> base2 = std::make_shared<Base2>();
    base2->SetBasePtr(basePtr);

    std::cout << basePtr.get() << std::endl;
    std::cout << basePtr.use_count() << std::endl;  
    std::cout << basePtr->i << std::endl;

 
    return 0;
}

