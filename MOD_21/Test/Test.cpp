#include <iostream>
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
	character person = { "Ifan-Ben-Mezd",100};
	person.armor = 20;
	character* person_ptr = &person;
	take_damage(&person, 30);

	std::cout << "Health:" << person.health << " Armor:" << person.armor << std::endl;
}
