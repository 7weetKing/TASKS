#include <iostream>
#include <fstream>
#include <string>

bool validDate(const std::string& date)
{
	if (date.length() != 10) 
		return false;
	if (date[2] != '.' || date[5] != '.') 
		return false;

	int day, month, year;

	day = std::stoi(date.substr(0, 2));
	month = std::stoi(date.substr(3, 2));
	year = std::stoi(date.substr(6, 4));

	if (day < 1 || day > 31)
		return false;
	if (month < 1 || month > 12) 
		return false;
	if (year < 1900 || year > 2200) 
		return false;

	return true;
}

int main()
{
	std::ofstream first("first.txt", std::ios::app);
	if (!first.is_open())
	{
		std::cerr << "Error opening file!" << std::endl;
		return 1;
	}

	std::string name, surname;
	double sum = 0;
	std::string date;

	std::cout << "Enter Name: ";
	std::cin >> name;
	std::cout << "Enter Surname: ";
	std::cin >> surname;
	std::cout << "Enter Date: ";
	std::cin >> date;
	std::cout << "Enter Sum: ";
	std::cin >> sum;

	first << name << " " << surname << " " << date << " " << sum << std::endl;

	std::cout << "added" << std::endl;
	first.close();

	return 0;
}
