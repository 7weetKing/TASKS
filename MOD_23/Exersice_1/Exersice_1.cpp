#include <iostream>
 
enum DATA {
	Monday = 1,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
	};

#define print_day(day,names) ((day >= Monday && day <= Sunday) ? names[day -1] : "Error")

int main()
{
	const char* name[] = {
		"Monday",
		"Tuesday",
		"Wednesday",
		"Thursday",
		"Friday",
		"Saturday",
		"Sunday"
	};

	int count = 0;
	std::cout << "Enter the day of the week (1-7): " << std::endl;
	std::cin >> count;

	DATA day = static_cast<DATA>(count);

	std::cout << print_day(day,name) << std::endl;
	
	return 0;
}