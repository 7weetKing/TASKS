#include <iostream>
#include "Function.h"

int main() 
{
    Point start{}, end{};
    std::string command;

    std::cout << "Start operation with 'scalpel' command: ";
    std::cin >> command >> start.x >> start.y >> end.x >> end.y;

    if (command != "scalpel") 
    {

        std::cout << "Operation must start with scalpel!\n";
        return 1;
    }
    scalpel(start, end);

    while (true)
    {
        std::cout << "Enter command: ";
        std::cin >> command;

        if (command == "hemostat" || command == "tweezers") 
        {
            Point location{};
            std::cin >> location.x >> location.y;
            if (command == "hemostat") hemostat(location);
            else tweezers(location);
        }
        else if (command == "suture") 
        {
            Point suture_start{}, suture_end{};
            std::cin >> suture_start.x >> suture_start.y >> suture_end.x >> suture_end.y;
            suture(suture_start, suture_end);
            if (suture_start == start && suture_end == end) 
            {
                std::cout << "Operation completed successfully.\n";
                break;
            }
            else 
            {
                std::cout << "Suture points must match the initial scalpel points!\n";
            }
        }
        else 
        {
            std::cout << "Invalid command. Available commands: scalpel, hemostat, tweezers, suture.\n";
        }
    }
    return 0;
}