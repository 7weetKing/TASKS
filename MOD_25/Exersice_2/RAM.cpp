#include "RAM.h"

static int buffer[8] = { 0 };

void write(int index, int value)
{
	if (index >= 0 && index < 8)
	{
		buffer[index] = value;
	}
}

int read(int index)
{
	if (index >= 0 && index < 8)
	{
		return buffer[index];
	}
	return 0;
}