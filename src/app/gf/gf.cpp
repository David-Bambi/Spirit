#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <uglad/uglad.hpp>
#include <uglfw/uglfw.hpp>
#include <def/GappDef.hpp>

void ExecuteGraphicApplication(const std::unique_ptr<Gapp>& gapp);

int main()
{
    std::cout << "Scenarios" << "\n"
              << "0. Exit\n"
              << "1. Empty Window\n"
              << "2. Triangle\n"
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
                ExecuteGraphicApplication(GappDef::EmptyWindowGapp);
                break;
            default:
                std::cout << "Invalid choice.\n";
                quit = true;
        }
    }

    return 0;
}

void ExecuteGraphicApplication(const std::unique_ptr<Gapp>& gapp)
{
    gapp->Init();
    gapp->Run();
    gapp->Shutdown();
}