#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::string fish;
	std::cout << "What kind of fish are you going to catch?: ";
	std::cin >> fish;

	std::ifstream file("river.txt");
	if (!file.is_open())
	{
		std::cerr << "Error opening file";
		return 1;
	}

	std::ofstream file2("basket.txt", std::ios::app);
	if (!file2.is_open())
	{
		std::cerr << "Error opening file2";
		return 1;
	}

	std::string caughtFish;
	int count = 0;
	while (file >> caughtFish)
	{
		if (caughtFish == fish)
		{
			file2 << caughtFish << std::endl;
			++count;
		}
	}

	file.close();
	file2.close();

	std::cout << "Caught: " << count << "\n" << "Fish species : " << fish << std::endl;

	return 0;

}