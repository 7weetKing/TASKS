#include <iostream>
#include <map>
#include <string>

class PhoneNumber 
{
    std::string number;
public:
    PhoneNumber() = default;
    PhoneNumber(const std::string& n) : number(n) {}
    std::string getNumber() const { return number; }
};

class Phone
{
    std::map<std::string, PhoneNumber> contacts;
public:
    void addContact(const std::string& name, const std::string& num)
    {
        contacts[name] = PhoneNumber(num);
        std::cout << "Добавлен контакт: " << name << " " << num << "\n";
    }

    void call(const std::string& who)
    {
        if (contacts.count(who))
        {
            std::cout << "CALL " << contacts[who].getNumber() << "\n";
        }
        else 
        {
            std::cout << "CALL " << who << "\n";
        }
    }

    void sms(const std::string& who, const std::string& text)
    {
        if (contacts.count(who))
        {
            std::cout << "SMS на " << contacts[who].getNumber() << ": " << text << "\n";
        }
        else 
        {
            std::cout << "SMS на " << who << ": " << text << "\n";
        }
    }
};

int main() 
{
    Phone phone;
    std::string cmd;
    while (true) 
    {
        std::cout << "\nВведите команду (add, call, sms, exit): ";
        std::cin >> cmd;
        if (cmd == "add")
        {
            std::string name, num;
            std::cout << "Имя: ";
            std::cin >> name;
            std::cout << "Номер: ";
            std::cin >> num;
            phone.addContact(name, num);
        }
        else if (cmd == "call") 
        {
            std::string who;
            std::cout << "Кому звонить: ";
            std::cin >> who;
            phone.call(who);
        }
        else if (cmd == "sms")
        {
            std::string who, text;
            std::cout << "Кому отправить: ";
            std::cin >> who;
            std::cout << "Текст: ";
            std::cin.ignore();
            std::getline(std::cin, text);
            phone.sms(who, text);
        }
        else if (cmd == "exit") 
        {
            break;
        }
    }
}