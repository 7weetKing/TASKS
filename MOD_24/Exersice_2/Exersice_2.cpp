#include <iostream>
#include <vector>
#include <ctime>
#include <sstream>

#define _CRT_SECURE_NO_WARNINGS
struct Friend 
{
    std::string name;
    int year, month, day;
};

std::vector<Friend> friends;

void get_birthdays() 
{
    while (true) 
    {
        std::string name;
        std::cout << "Enter friend's name (or 'end' to finish): ";
        std::cin >> name;
        if (name == "end") break;

        std::string date;
        std::cout << "Enter birthday (YYYY/MM/DD): ";
        std::cin >> date;

        std::istringstream ss(date);
        int year, month, day;
        char sep1, sep2;
        if (ss >> year >> sep1 >> month >> sep2 >> day && sep1 == '/' && sep2 == '/') 
        {
            friends.push_back({ name, year, month, day });
        }
        else 
        {
            std::cout << "Error: invalid date format. Please use YYYY/MM/DD.\n";
        }
    }
}

void find_nearest_birthday() 
{
    if (friends.empty())
    {
        std::cout << "No birthdays stored." << std::endl;
        return;
    }

    time_t t = time(nullptr);
    tm now;
    if (localtime_s(&now, &t) != 0) {
        std::cerr << "Error time\n";
        return;
    }
    int current_year = now.tm_year + 1900;
    int current_month = now.tm_mon + 1;
    int current_day = now.tm_mday;
    int min_days_diff = 365;
    Friend* nearest = nullptr;

    for (auto& f : friends) 
    {
        int days_diff;
        tm birthday = {};
        birthday.tm_year = current_year - 1900;
        birthday.tm_mon = f.month - 1;
        birthday.tm_mday = f.day;

        time_t b_time = mktime(&birthday);
        if (b_time < t) 
        {
            birthday.tm_year += 1;
            b_time = mktime(&birthday);
        }

        days_diff = (b_time - t) / (60 * 60 * 24);

        if (days_diff == 0) 
        {
            std::cout << "Today is " << f.name << "'s birthday!" << std::endl;
        }
        else if (days_diff < min_days_diff)
        {
            min_days_diff = days_diff;
            nearest = &f;
        }
    }

    if (nearest) 
    {
        std::cout << "The nearest birthday is " << nearest->name << " on " << nearest->month << "/" << nearest->day << "." << std::endl;
    }
}

int main() 
{
    get_birthdays();
    find_nearest_birthday();
    return 0;
}
