#include "GPU.h"
#include "RAM.h"
#include <iostream>

void display()
{
	std::cout << "RAM content: ";
	for (int i = 0; i < 8; i++)
	{
		std::cout << read(i) << " ";
	}
	std::cout << std::endl;
}
