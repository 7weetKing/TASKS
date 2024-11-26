#include <iostream>
#include <fstream>
#include <string> 
#include <vector>


struct statement
{
	std::string name;
	std::string surname;
	std::string date;
	double sum;

	void result()const
	{
		std::cout << name << " " << surname << " " << date << " " << sum << std::endl;
	}
};



bool validDate(const std::string & date)
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

std::vector<statement> readRecords(const std::string& filename) 
{
	std::vector<statement> records;
	std::ifstream file(filename);
	if (!file.is_open())
	{
		std::cerr << "Error opening file!" << std::endl;
		return records;
	}

	while (!file.eof()) 
	{
		statement record;
		file >> record.name >> record.surname >> record.date >> record.sum;
		if (file.eof())
			break;
		records.push_back(record);
	}

	file.close();
	return records;
}

void addRecord(const std::string& filename, const statement& record) 
{
	std::ofstream file(filename, std::ios::app);
	if (!file.is_open()) 
	{
		std::cerr << "Error opening file!" << std::endl;
		return;
	}

	file << record.name << " " << record.surname << " " << record.date << " " << record.sum << std::endl;
	file.close();
}

void clearFile(const std::string& filename) 
{
	std::ofstream file(filename, std::ios::trunc);
	if (!file.is_open())
	{
		std::cerr << "Error opening file!" << std::endl;
		return;
	}
	file.close();
	std::cout << "File cleared successfully." << std::endl;
}

int main() 
{
	const std::string filename = "first.txt";
	std::string command;

	std::cout << "Enter command (list or add or clear): ";
	std::cin >> command;

	if (command == "list") 
	{
		std::vector<statement> records = readRecords(filename);
		if (records.empty())
		{
			std::cout << "No records found." << std::endl;
		}
		else 
		{
			for (const auto& record : records) 
			{
				record.result();
			}
		}
	}
	else if (command == "add") 
	{
		statement newRecord;
		std::cout << "Enter Name: ";
		std::cin >> newRecord.name;
		std::cout << "Enter Surname: ";
		std::cin >> newRecord.surname;
		do 
		{
			std::cout << "Enter Date (DD.MM.YYYY): ";
			std::cin >> newRecord.date;
			if (!validDate(newRecord.date)) 
			{
				std::cout << "Invalid date format. Try again." << std::endl;
			}
		} while (!validDate(newRecord.date));
		std::cout << "Enter Sum: ";
		std::cin >> newRecord.sum;

		addRecord(filename, newRecord);
		std::cout << "Record added successfully." << std::endl;
	}
	else if (command == "clear")
	{
		clearFile(filename);
	}
	else 
	{
		std::cerr << "Invalid command!" << std::endl;
	}

	return 0;
}