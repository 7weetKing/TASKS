#include <iostream>
#include <ctime>
#include <string>
#include <map>

std::map<std::string, double> program_times;
std::string current_program;
std::time_t start_time;
bool program_active = false;
void end_program();

void start_program(const std::string& program_name)
{
	if (program_active)
	{
		end_program();
	}
	current_program = program_name;
	start_time = std::time(nullptr);
	program_active = true;
	std::cout << "New task started: " << current_program << std::endl;
}

void end_program()
{
	if (program_active)
	{
		std::time_t end_time = std::time(nullptr);
		double time_hour = std::difftime(end_time, start_time);
		program_times[current_program] += time_hour;
		std::cout << "Completed task: " << current_program << "spent " << time_hour << " hour" << std::endl;
		program_active = false;
	}
}

void status()
{
	std::cout << "Program status: " << std::endl;
	for (const auto& program : program_times)
	{
		std::cout << "Task: " << program.first << " - " << program.second << "hour" << std::endl;
	}

	if (program_active)
	{
		std::cout << "Current task: " << current_program << std::endl;
	}
}

int main()
{
	std::string com;

	while (true)
	{
		std::cout << "Enter command (begin, end, status, exit): ";
		std::cin >> com;

		if (com == "begin") {
			std::cout << "Enter the task name: ";
			std::string programs_name;
			std::cin >> programs_name;
			std::getline(std::cin, programs_name);
			start_program(programs_name);
		}
		else if (com == "end") 
		{
			end_program();
		}
		else if (com == "status")
		{
			status();
		}
		else if (com == "exit") 
		{
			end_program();
			break;
		}
		else {
			std::cout << "Unknown team!" << std::endl;
		}
	}
	return 0;
}