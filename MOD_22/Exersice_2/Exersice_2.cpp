#include <iostream>
#include <map>
#include <string>

int main()
{
	std::map<std::string, int> List;
	std::string command;

	while (std::cin  >> command)
	{
		if (command == "Next")
		{

			if (!List.empty())
			{
				for (std::map<std::string, int>::iterator it = List.begin();
					it != List.end(); ++it)
				{
					std::cout << "->" << it->first << std::endl;

					if (it->second > 1)
					{
						it->second--;
						break;
					}
					else
					{
						List.erase(it);
						break;
					}
				}
			}
			else
			{
				std::cout << "List is empty" << std::endl;
			}
		}
		else
		{
			List[command]++;
		}

		if (command == "Exit")
		{
			break;
		}
	}
	return 0;
}