#include <iostream>
#include <string>
#include "CPU.h"
#include "RAM.h"
#include "DISK.h"
#include "GPU.h"
#include "KBD.h"

int main() 
{
    std::string command;

    while (true) 
    {
        std::cout << " > ";
        std::cin >> command;

        if (command == "sum") 
        {
            computer();
        }
        else if (command == "save")
        {
            save();
        }
        else if (command == "load")
        {
            load();
        }
        else if (command == "input")
        {
            input();
        }
        else if (command == "display")
        {
            display();
        }
        else if (command == "exit") 
        {
            break;
        }
        else 
        {
            std::cout << "Unknown command." << std::endl;
        }
    }

    return 0;
}
