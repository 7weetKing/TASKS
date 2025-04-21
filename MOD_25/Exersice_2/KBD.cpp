#include "KBD.h"
#include "RAM.h"
#include <iostream>

void input()
{
	std::cout << "Enter 8 integers: ";
	for (int i = 0; i < 8; i++)
	{
		int value;
		std::cin >> value;
		write(i, value);
	}
}