#include <iostream>
#include <math.h>

void armata_go()
{
	//Go
}

void armata_stop()
{
	//Stop	
}

void armata_shoot(int count)
{
	for (int i = 0; i < count; ++i)
	{
		std::cout << "Shot!" << std::endl;
	}
}

#define TANK(model, name) model ## _ ## name

int main()
{
	double armata_weight = 49.5;
	int armata_capacity = 3;
	double armata_max_speed = 90;
	
#if 0
	std::cout << TANK(armata, weight) << std::endl;
	TANK(armata, weight) = 55;
	std::cout << TANK(armata, weight) << std::endl;
#endif

	TANK(armata, shoot)(5);

}