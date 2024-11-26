/*#include <iostream>
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
}*/
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

class Item {
public:
	std::string name;
	Item(std::string n) : name(n) {}
};

class Enemy {
public:
	std::string name;
	int health;
	Enemy(std::string n, int h) : name(n), health(h) {}

	void takeDamage(int damage) {
		health -= damage;
		if (health < 0) health = 0;
	}
};

class Player {
public:
	int health;
	std::vector<Item> inventory;

	Player() : health(100) {}

	void addItem(const Item& item) {
		inventory.push_back(item);
		std::cout << "Вы нашли: " << item.name << "!" << std::endl;
	}

	void attack(Enemy& enemy) {
		int damage = rand() % 20 + 5; // Урон от 5 до 25
		std::cout << "Вы атаковали " << enemy.name << " и нанесли " << damage << " урона!" << std::endl;
		enemy.takeDamage(damage);
	}

	void heal(int amount) {
		health += amount;
		if (health > 100) health = 100;
		std::cout << "Вы восстановили " << amount << " здоровья! Текущее здоровье: " << health << std::endl;
	}
};

void showStatus(Player& player, Enemy& enemy) {
	std::cout << "Ваше здоровье: " << player.health << std::endl;
	std::cout << enemy.name << " здоровье: " << enemy.health << std::endl;
}

int main() {
	std::srand(static_cast<unsigned int>(std::time(0)));

	Player player;
	Enemy goblin("Гоблин", 50);
	std::vector<Item> items = { Item("Зелье здоровья"), Item("Меч"), Item("Щит") };

	std::cout << "Добро пожаловать в приключенческую игру!" << std::endl;

	while (goblin.health > 0 && player.health > 0) {
		std::cout << "\nВы находитесь в темной комнате. Что вы хотите сделать?" << std::endl;
		std::cout << "1. Искать предметы" << std::endl;
		std::cout << "2. Атаковать гоблина" << std::endl;
		std::cout << "3. Использовать зелье здоровья" << std::endl;

		int choice;
		std::cin >> choice;

		switch (choice) {
		case 1: {
			// Найти случайный предмет
			int itemIndex = rand() % items.size();
			player.addItem(items[itemIndex]);
			break;
		}
		case 2: {
			player.attack(goblin);
			break;
		}
		case 3: {
			player.heal(20);
			break;
		}
		default:
			std::cout << "Неверный выбор. Попробуйте снова." << std::endl;
			continue;
		}

		// Ответ гоблина
		if (goblin.health > 0) {
			int damage = rand() % 15 + 5; // Урон гоблина
			player.health -= damage;
			std::cout << "Гоблин атакует вас и наносит " << damage << " урона!" << std::endl;
		}

		showStatus(player, goblin);
	}

	if (goblin.health == 0) {
		std::cout << "Вы победили гоблина!" << std::endl;
	}
	else {
		std::cout << "Вы погибли... Игра окончена." << std::endl;
	}

	return 0;
}