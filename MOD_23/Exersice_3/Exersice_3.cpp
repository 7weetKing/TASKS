#include <iostream>
#include <string>

const int count_carriage = 10;

#define CALL(func, arr, index) { func(arr[index], index + 1); }

void over_pass(int passengers, int carriage_number)
{
	if (passengers > 20)
	{
		std::cout << "Carriage:"<< carriage_number << "crowded! Number of passengers:" << passengers << std::endl;
	}
}

void check_pass(int passengers, int wagon_number)
{
	if (passengers < 20)
	{
		std::cout << "In the carriage" << wagon_number << "there are free places. Number of passengers: " << passengers << std::endl;
	}
}

int total_pass = 0;
void count_pass (int passengers,int)
{
	total_pass += passengers;
}

int main()
{
	int passengers[count_carriage];

	std::cout << "Enter the number of passengers in each of the 10 carriage: " << passengers << std::endl;
	for (int i = 0; i < count_carriage; ++i)
	{
		std::cout << "Carriage: " << i + 1 << std::endl;
		std::cin >> passengers[i];
	}

	std::cout << "Carriage occupancy: " << std::endl;
	for (int i = 0; i < count_carriage; ++i)
	{
		CALL(over_pass, passengers, i);
	}

	for (int i = 0; i < count_carriage; ++i)
	{
		CALL(check_pass, passengers, i);
	}

	for (int i = 0; i < count_carriage; ++i)
	{
		CALL(count_pass, passengers, i);
	}

	std::cout << "Total number of passengers on the train: " << total_pass << std::endl;

	return 0;
}