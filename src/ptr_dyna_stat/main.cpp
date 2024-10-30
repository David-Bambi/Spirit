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

    const DerivedB* DerB = static_cast<const DerivedB*>(ptr);

    // Ici DerB a été caster en DerivedB à partir du ptr 
    // void. Donc même si il a le type DerivedB l'objet à 
    // l'intérieur est un DerivedA. C'est ainsi parce qu'on 
    // ne sait pas ce qu'on peut passer à fonction avant 
    // l'exécution.

    // bref, ici on fait une liaison dynamique parce que 
    // DisplayB est virtuel. Donc la fonction va être décidée 
    // à l'exécution. 

    // on peut corriger l'erreur avec ces façons
    // 1 : Si possible, enlever le mot virtuel à la fonction
    //     DisplayB, ainsi la fonction ne sera pas évaluée. 
    //     Statiquement.
    //
    // 2 : On peut aussi utiliser la notation class::fct
    //     Pour forcer l'appel à la fonction.
    DerB->DisplayB();
}

int main() {

   Base* Base = new DerivedA();

   callPrint(Base); 

   delete Base;
   return 0;
}
