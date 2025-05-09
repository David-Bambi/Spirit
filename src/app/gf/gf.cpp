#include <glad/glad.h>
#include <def/GappDef.hpp>
#include <gapp/Gapp.hpp>
#include <iostream>
#include <memory>

int main()
{
    std::cout << "Scenarios" << "\n"
              << "0. Exit\n"
              << "1. Empty Window\n"
              << "2. Shape\n"
              << "3. Model scenario\n"
              << "4. Texture scenario\n"
              << "5. Shader scenario\n"
              << "6. Light scenario\n"
              << "7. Camera scenario\n"
              << "8. Animation scenario\n"
              << "9. Physics scenario\n";

    bool quit = false;
    int choice = -1;
    while (!quit)
    {
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
            case 0:
                std::cout << "Exiting...\n";
                quit = true;
                break;
            case 1:
                GappDef::EmptyWindowGapp->Run();
                break;
            case 2:
                GappDef::ShapeGapp->Run();
                break;
            default:
                std::cout << "Invalid choice.\n";
                quit = true;
        }
    }

    return 0;
}
