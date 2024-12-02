#include <iostream>
#include <fstream>
#include <string> 
#include <vector>
#include <cstdlib>

struct village
{
	struct plot
	{
		int plot_number = 0;
		double plot_area = 0;

		enum plot_type
		{
			garage,
			barn,
			bathhouse
		};

		struct buildings
		{
			plot_type type;
			double buildings_areea = 0;

			struct House
			{
				int floor = 0;
				bool stove;

				struct Room
				{
					double room_type = 0;

					enum room_type
					{
						bedroom,
						kitchen,
						bathroom,
						children,
						livingRoom
					};
				};

				std::vector < std::vector<Room>> floors_rooms;

				House(int num_floors) : floor(num_floors), stove(false)
				{
					floors_rooms.resize(num_floors);
				}
			};

			
		};
		
		std::vector<buildings> buildings;

		plot(int number, double area) : plot_number(number), plot_area(area)
		{
		}
	};

	std::vector <plot>plots;

	void addPlot(int number, double area)
	{
		plot new_plot(number, area);
		plots.push_back(new_plot);
	}
};

void display_Village(const village& Village)
{
	double used_area = 0;
	double total_area = 0;


}



int main()
{

}