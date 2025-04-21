#include <iostream>

struct Point 
{
    double x, y;

    void input() 
    {
        std::cin >> x >> y;
    }
    void display() const 
    {
        std::cout << "(" << x << ", " << y << ")";
    }
    bool operator==(const Point& other) const 
    {
        return std::fabs(x - other.x) < 1e-6 && std::fabs(y - other.y) < 1e-6;
    }
};

void scalpel(const Point& start, const Point& end)
{
    std::cout << "Scalpel: incision made from ";
    start.display();
    std::cout << " to ";
    end.display();
    std::cout << "\n";
}

void hemostat(const Point& location) 
{
    std::cout << "Hemostat: applied at ";
    location.display();
    std::cout << "\n";
}

void tweezers(const Point& location) 
{
    std::cout << "Tweezers: applied at ";
    location.display();
    std::cout << "\n";
}

void suture(const Point& start, const Point& end) 
{
    std::cout << "Suture: stitching from ";
    start.display();
    std::cout << " to ";
    end.display();
    std::cout << "\n";
}