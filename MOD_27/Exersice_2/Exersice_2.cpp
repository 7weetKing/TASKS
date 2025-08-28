#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>

class Employee 
{
public:
    std::string name;
    Employee(std::string n) : name(n) {}
    virtual void doTask(int command) = 0;
    std::string getName() const { return name; }
};

class Worker : public Employee 
{
public:
    Worker(std::string n) : Employee(n) {}
    void doTask(int command) override 
    {
        char type = 'A' + rand() % 3;
        std::cout << "Worker " << name << " performs the task " << type << std::endl;
    }
};

class Manager : public Employee 
{
    int id;
    std::vector<Worker*> team;
public:
    Manager(std::string n, int id) : Employee(n), id(id) {}
    void addWorker(Worker* w) { team.push_back(w); }
    void doTask(int command) override
    {
        int seed = command + id;
        srand(seed);
        int tasksCount = rand() % (team.size() + 1);
        std::cout << "Manager " << name << " received " << tasksCount << " task" << std::endl;
        for (int i = 0; i < tasksCount && i < team.size(); i++)
        {
            team[i]->doTask(command);
        }
    }
};

class CEO : public Employee
{
    std::vector<Manager*> managers;
public:
    CEO(std::string n) : Employee(n) {}
    void addManager(Manager* m) { managers.push_back(m); }
    void doTask(int command) override
    {
        std::cout << "CEO " << name << " received the command " << command << std::endl;
        for (auto m : managers) m->doTask(command);
    }
};

int main()
{
    int teams, workersPerTeam;
    std::cout << "Enter the number of teams and workers in each: ";
    std::cin >> teams >> workersPerTeam;

    CEO ceo("Chapter");

    std::vector<Manager*> managers;
    for (int i = 0; i < teams; i++)
    {
        Manager* m = new Manager("Manager_" + std::to_string(i + 1), i + 1);
        for (int j = 0; j < workersPerTeam; j++) 
        {
            m->addWorker(new Worker("Worker_" + std::to_string(i + 1) + "_" + std::to_string(j + 1)));
        }
        ceo.addManager(m);
        managers.push_back(m);
    }

    std::cout << "Enter commands (integers), 0 to exit: ";
    int cmd;
    while (std::cin >> cmd && cmd != 0) 
    {
        ceo.doTask(cmd);
    }
}