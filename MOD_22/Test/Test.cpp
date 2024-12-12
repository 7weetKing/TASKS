#include<iostream>
#include <map>
#include <string>
void main()
{
	std::pair<std::string, int>oPair("Hello", 5);
	std::map<std::string, int>ourMap;
	ourMap.insert(oPair);

	std::cout << oPair.first << " " << std::endl;

	ourMap.insert(std::pair<std::string, int>("World", 6));
	ourMap.insert(std::make_pair<std::string, int>("banana", 7));

	ourMap.insert(std::pair<std::string, int>("Hello", 8));

	std::cout << ourMap["Hello"] << std::endl;
}