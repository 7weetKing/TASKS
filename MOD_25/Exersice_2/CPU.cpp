#include "CPU.h"
#include "RAM.h"
#include <iostream>

void computer()
{
	int sum = 0;
	for (int i = 0; i < 8; i++)
	{
		sum += read(i);
	}
	std::cout << "Sum: " << sum << std::endl;
}