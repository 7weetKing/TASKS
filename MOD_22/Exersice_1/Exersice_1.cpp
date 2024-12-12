#include <iostream>
#include <map>
#include <vector>
#include <string>

int main() {

    std::map<std::string, std::string> phone_to_name;

    std::map<std::string, std::vector<std::string>> name_to_phones;

    std::string command;

    while (true) {
        std::cout << "Enter a command (add, search, or exit): " << std::endl;
        std::cin >> command;

        if (command == "add") 
        {
            std::string phone, name;
            std::cout << "Enter phone: ";
            std::cin >> phone;
            std::cout << "Enter name: ";
            std::cin >> name;

            phone_to_name[phone] = name;
            name_to_phones[name].push_back(phone);

        }
        else if (command == "search") 
        {
            std::string search_type;
            std::cout << "Search by 'number' or 'name': " << std::endl;
            std::cin >> search_type;

            if (search_type == "number") 
            {
                std::string phone;
                std::cout << "Enter phone: ";
                std::cin >> phone;

                if (phone_to_name.find(phone) != phone_to_name.end()) 
                {
                    std::cout << "Name: " << phone_to_name[phone] << std::endl;
                }
                else {
                    std::cout << "Phone number not found." << std::endl;
                }

            }
            else if (search_type == "name") 
            {
                std::string name;
                std::cout << "Enter name: ";
                std::cin >> name;

                if (name_to_phones.find(name) != name_to_phones.end()) 
                {
                    std::cout << "Phone(s): ";
                    for (const auto& phone : name_to_phones[name]) 
                    {
                        std::cout << phone << " ";
                    }
                    std::cout << std::endl;
                }
                else
                {
                    std::cout << "Name not found." << std::endl;
                }
            }
            else 
            {
                std::cout << "Invalid search type." << std::endl;
            }

        }
        else if (command == "exit") 
        {
            break;
        }
        else 
        {
            std::cout << "Invalid command." << std::endl;
        }
    }

    return 0;
}
