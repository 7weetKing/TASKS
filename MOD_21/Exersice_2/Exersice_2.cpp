#include <iostream>
#include <vector>

enum room_type 
{
	bedroom,
	kitchen,
	bathroom,
	children,
	livingRoom,
};

struct Room 
{
	int Room_numbers;
	double area = 0;
};

struct Floor 
{
	int floor_numbers;
	double height = 0;
	std::vector<Room> Rooms;
};

enum building_type 
{
	house,
	garage,
	bathhouse,
	barn,
};

struct building 
{
	bool has_chimney;
	double area = 0;
	building_type type;
	std::vector<Floor> Floors;
};

struct plot 
{
	int plot_numbers;
	std::vector<building> buildings;
	double area;
};

struct Village 
{
	std::vector<plot> plots;
};

Room creat_room()
{
	Room room;
	int room_type;
	std::cout << "Enter rooms type (bedroom(0), kitchen(1), bathroom(2), children(3), livingRoom(4)): ";
	std::cin >> room_type;

	std::cout << "Enter rooms area: ";
	std::cin >> room.area;
	return room;
}

Floor creat_floor()
{
	Floor floor;
	std::cout << "Enter the number of floor: ";
	std::cin >> floor.floor_numbers;
	std::cout << "Enter ceiling height: ";
	std::cin >> floor.height;

	int room_count;
	std::cout << "Enter the number of rooms on the floor: ";
	std::cin >> room_count;

	for (int i = 0; i < room_count; ++i)
	{
		std::cout << "Floor " << (i + 1);
		floor.Rooms.push_back(creat_room());
	}
	return floor;
}

building creat_building()
{
	building Building;
	int type;
	std::cout << "Enter building type (house(0), garage(1), bathhouse(2), barn(3)): ";
	std::cin >> type;

	std::cout << "Enter building area: ";
	std::cin >> Building.area;

	if (type == house || type == bathhouse)
	{
		std::cout << "Is there a pipe? (1 - yes, 0 - no): ";
		std::cin >> Building.has_chimney;
	}
	else
	{
		Building.has_chimney = false;
	}

	if (type == house)
	{
		int count;
		std::cout << "Enter the number of floors in the house: ";
		std::cin >> count;
		for (int i = 0; i < count; ++i)
		{
			std::cout << "Floor " << (i + 1);
			Building.Floors.push_back(creat_floor());
		}
	}
	return Building;
}

plot creat_plot(int plotNumber)
{
	plot Plot;
	Plot.plot_numbers = plotNumber;

	std::cout << "Enter area plot: ";
	std::cin >> Plot.area;

	int buildingCount;
	std::cout << "Enter the number of buildings on the plot: ";
	std::cin >> buildingCount;

	for (int i = 0; i < buildingCount; ++i)
	{
		std::cout << "Build" << (i + 1);
		Plot.buildings.push_back(creat_building());
	}
	return Plot;
}

Village creat_village()
{
	Village village;
	int plot_count;
	std::cout << "Enter the number of plots in the village: ";
	std::cin >> plot_count;

	for (int i = 0; i < plot_count; ++i)
	{
		std::cout << "Plot " << (i + 1);
		village.plots.push_back(creat_plot(i + 1));
	}
	return village;
}

double display_Village(const Village& village)
{
	double total_area = 0;
	double used_area = 0;

	for (size_t i = 0; i < village.plots.size(); ++i)
	{
		total_area += village.plots[i].area;

		for (size_t j = 0; j < village.plots[i].buildings.size(); ++i)
		{
			used_area += village.plots[i].buildings[j].area;
		}
	}
	return (total_area > 0) ? (used_area / total_area) * 100 : 0;
}

int main()
{
	Village village = creat_village();

	double Percent = display_Village(village);
	std::cout << "Percentage of land occupied by buildings: " << Percent << "%" << std::endl;

	return 0;
}