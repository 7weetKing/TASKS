#include <iostream>
#include <cstdlib>
#include <string>

struct character
{
	std::string name = "unknown";
	int health = 0;
	int armor = 0;
};

void take_damage(character* person, int damage)
{
	std::cout << person->name << "took damage: -" << damage << std::endl;
	person->armor -= damage;
	if (person->armor < 0)
	{
		person->health += person->armor;
		person->armor = 0;
	}

}

int main()
{
	character people[10];
	for (int i = 0; i < 10; ++i)
	{
		people[i].name = "Character #" + std::to_string(i);
		people[i].health = (std::rand() % 100) + 100;
		people[i].armor = (std::rand() % 40) + 10;
	}

	for (int i = 0; i < 10; ++i)
	{
		take_damage(&people[i], 30);
	}
}
