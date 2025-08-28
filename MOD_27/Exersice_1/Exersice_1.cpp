#include <iostream>
#include <cmath>
#include <string>

enum class Color { None, Red, Blue, Green };

class Figure 
{
protected:
    double x, y;
    Color color;
public:
    Figure(double x, double y, Color c) : x(x), y(y), color(c) {}
    virtual double area() const = 0;
    virtual void boundingBox() const = 0;
    virtual ~Figure() {}
};

class Circle : public Figure 
{
    double r;
public:
    Circle(double x, double y, Color c, double r) : Figure(x, y, c), r(r) {}
    double area() const override { return 3.14159265358979323846 * r * r; }
    void boundingBox() const override {
        std::cout << "Bounding box: (" << x - r << "," << y - r
            << ") - (" << x + r << "," << y + r << ")\n";
    }
};

class Square : public Figure
{
    double a;
public:
    Square(double x, double y, Color c, double a) : Figure(x, y, c), a(a) {}
    double area() const override { return a * a; }
    void boundingBox() const override {
        double half = a / 2;
        std::cout << "Bounding box: (" << x - half << "," << y - half
            << ") - (" << x + half << "," << y + half << ")\n";
    }
};

class Triangle : public Figure 
{
    double a;
public:
    Triangle(double x, double y, Color c, double a) : Figure(x, y, c), a(a) {}
    double area() const override { return a * a * std::sqrt(3) / 4; }
    void boundingBox() const override {
        double height = a * std::sqrt(3) / 2;
        std::cout << "Bounding box: (" << x - a / 2 << "," << y - height / 3
            << ") - (" << x + a / 2 << "," << y + 2 * height / 3 << ")\n";
    }
};

class Rectangle : public Figure 
{
    double w, h;
public:
    Rectangle(double x, double y, Color c, double w, double h) : Figure(x, y, c), w(w), h(h) {}
    double area() const override { return w * h; }
    void boundingBox() const override {
        std::cout << "Bounding box: (" << x - w / 2 << "," << y - h / 2
            << ") - (" << x + w / 2 << "," << y + h / 2 << ")\n";
    }
};

int main() 
{
    std::string cmd;
    std::cout << "Enter the figure: (circle, square, triangle, rectangle): ";
    std::cin >> cmd;

    if (cmd == "circle") 
    {
        double x, y, r; std::cin >> x >> y >> r;
        Circle c(x, y, Color::Red, r);
        std::cout << "Square: " << c.area() << std::endl;
        c.boundingBox();
    }
    else if (cmd == "square")
    {
        double x, y, a; std::cin >> x >> y >> a;
        Square s(x, y, Color::Blue, a);
        std::cout << "Square: " << s.area() << std::endl;
        s.boundingBox();
    }
    else if (cmd == "triangle")
    {
        double x, y, a; std::cin >> x >> y >> a;
        Triangle t(x, y, Color::Green, a);
        std::cout << "Square: " << t.area() << std::endl;
        t.boundingBox();
    }
    else if (cmd == "rectangle")
    {
        double x, y, w, h; std::cin >> x >> y >> w >> h;
        Rectangle r(x, y, Color::Red, w, h);
        std::cout << "Square: " << r.area() << std::endl;
        r.boundingBox();
    }
}