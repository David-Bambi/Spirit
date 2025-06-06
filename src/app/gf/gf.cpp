#include <glad/glad.h>

#include <gimporter/GJsonImporter.hpp>
#include <debug/DebugHandler.hpp>
#include <iostream>
#include <gapp/Gapp.hpp>
#include <memory>

void Execute(std::string name);

int main()
{
    DebugHandler::SetupCrashHandler();

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
                Execute("EmptyWindow");
                break;
            default:
                std::cout << "Invalid choice.\n";
                quit = true;
        }
    }

    return 0;
}

void Execute(std::string name)
{
    std::shared_ptr<Gapp> App = GJsonImporter::ImportGapp(name);
    if (App != nullptr)
        App->Run();
}