#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

int main()
{
	std::srand(std::time(nullptr));

	std::ofstream file("pic.txt", std::ios::binary);
	if (!file.is_open())
	{
		std::cerr << "Error opening file!";
		return 1;
	}

	int height = 0;
	int length = 0;

	std::cout << "Enter height: ";
	std::cin >> height;
	std::cout << "Enter length: ";
	std::cin >> length;

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < length; ++j)
		{
			int random = std::rand() % 2;
			file << random;
		}

		file << "\n";
	}
	
	file.close();

	std::cout << "Binary picture written to pic.txt" << std::endl;

}