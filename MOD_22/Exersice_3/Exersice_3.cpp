#include <iostream>
#include <map>
#include <string>

bool Anograms(std::string& str1,std::string& str2)
{
	std::map<char, int> count;

	for (std::string::iterator it = str1.begin(); it != str1.end(); ++it)
	{
		char ch = *it;
		count[ch]++;
	}

	for (std::string::iterator it = str2.begin(); it != str2.end(); ++it)
	{
		char ch = *it;

		if (count.find(ch) == count.end())
		{
			return false;
		}

		count[ch]--;
	}

	for (std::map<char, int>::iterator it = count.begin(); it != count.end(); ++it)
	{
		if (it->second != 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	std::string str1, str2;

	std::cout << "Enter 1 string: ";
	std::getline(std::cin, str1);

	std::cout << "Enter 2 string: ";
	std::getline(std::cin, str2);

	if (Anograms(str1, str2))
	{
		std::cout << "Yes";
	}
	else
	{
		std::cout << "No";
	}
	return 0;
}