#include "DISK.h"
#include "RAM.h"
#include <fstream>

void save()
{
	std::ofstream out("save.txt");
	for (int i = 0; i < 8; i++)
	{
		out << read(i) << " ";
	}
	out.close();
}

void load()
{
	std::ifstream in("load.txt");
	int value;
	for (int i = 0; i<8 && in >> value; i++)
	{
		write(i, value);
	}
	in.close();
}