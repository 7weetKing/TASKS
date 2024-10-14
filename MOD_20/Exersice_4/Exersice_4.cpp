#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

const int maxBanknote = 1000;
const std::vector<int> nominals = {100,200,500,1000,2000,5000};

void saveState(const std::vector<int>& bills)
{
	std::ofstream outFile("ATM.bin", std::ios::binary);
	if (!outFile.is_open())
	{
		std::cerr << "Error opening file!";
		return;
	}
	outFile.write(reinterpret_cast<const char*>(bills.data()), bills.size() * sizeof(int));
	outFile.close();
}

bool loadFile(std::vector<int>& bills)
{
	std::ifstream inFile("ATM.bin", std::ios::binary);
	if (!inFile)
	{
		return false;
	}
	inFile.read(reinterpret_cast<char*>(bills.data()), bills.size() * sizeof(int));
	inFile.close();
	return true;
}

void displayState(const std::vector<int>& bills)
{
	int totalMoney = 0, totalBills = 0;
	std::cout << "Current ATM status:\n";
	for (int i = 0; i < nominals.size(); ++i)
	{
		std::cout << nominals[i] << " RUB: " << bills[i] << " banknote.\n";
		totalMoney += nominals[i] * bills[i];
		totalBills += bills[i];
	}
	std::cout << "Total number of banknotes: " << totalBills << std::endl;
	std::cout << "Total amount of money: " << totalMoney << std::endl;
}

void refillAtm(std::vector<int>& bills) 
{
	std::srand(std::time(nullptr));
	int currentBills = 0;
	for (int bill : bills)
	{
		currentBills += bill;
	}

	while (currentBills < maxBanknote)
	{
		int randomIndex = rand() % nominals.size();
		bills[randomIndex]++;
		currentBills++;
	}

	std::cout << "ATM successfully replenished!" << std::endl;
	displayState(bills);
}

void withdraw(std::vector<int>& bills, int count)
{
	if (count % 100 != 0)
	{
		std::cout << "The amount must be a multiple of 100 rubles!" << std::endl;
		return;
	}

	std::vector<int> billsToWithdraw(bills.size(), 0);

	for (int i = nominals.size() - 1; i >= 0; --i)
	{
		while (count >= nominals[i] && bills[i] > 0)
		{
			count -= nominals[i];
			billsToWithdraw[i]++;
			bills[i]--;
		}
	}

	if (count == 0)
	{
		std::cout << "Operation successful! Issued!" << std::endl;
		for (int i = 0; i < nominals.size(); ++i)
		{
			if (billsToWithdraw[i] > 0)
			{
				std::cout << nominals[i] << "RUB: " << billsToWithdraw[i] << " banknote." << std::endl;
			}
		}
	}
	else
	{
		std::cout << "It is not possible to issue the requested amount." << std::endl;
		for (int i = 0; i < nominals.size(); ++i)
		{
			bills[i] += billsToWithdraw[i];
		}
	}

	displayState(bills);
}

int main()
{
	std::vector<int> bills(nominals.size(), 0);

	if (!loadFile(bills))
	{
		std::cout << "ATM is empty." << std::endl;
	}
	else
	{
		std::cout << "Data loaded." << std::endl;
		displayState(bills);
	}
	char com;
	while (true) 
	{
		std::cout << "Enter '+' to deposit, '-' to withdraw, 'q' to exit: ";
		std::cin >> com;

		if (com == '+') 
		{
			refillAtm(bills);
		}
		else if (com == '-') 
		{
			int amount;
			std::cout << "Enter the amount to withdraw: ";
			std::cin >> amount;
			withdraw(bills, amount);
		}
		else if (com == 'q')
		{
			saveState(bills);
			std::cout << "ATM status saved. Exit program." << std::endl;
			break;
		}
		else 
		{
			std::cout << "Invalid command. Try again." << std::endl;
		}
	}

	return 0;
}