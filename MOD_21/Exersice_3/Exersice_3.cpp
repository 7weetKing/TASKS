#include <iostream>
#include<cmath>	

struct vec
{
	double x, y;

	vec(double x=0,double y=0) : x(x),y(y){}

	void conclusion() const
	{
		std::cout << "(" << x << "," << y << ")" << std::endl;
	}
};

vec add(const vec& a, const vec& b)
{
	return vec(a.x + b.x, a.y + b.y);
}

vec subtract(const vec& a, const vec& b)
{
	return vec(a.x - b.x, a.y - b.y);
}

vec scale(const vec& a, double scale)
{
	return vec(a.x * scale, a.y * scale);
}

double length(const vec& a)
{
	return sqrt(a.x * a.x + a.y * a.y);
}

vec normalize(const vec& a) 
{
	double len = length(a);
	if (len == 0)
	{
		return vec(0, 0);
	}

	return vec(a.x / len, a.y / len);
}

int main()
{
	vec a, b;
	double scalar;
	std::string enter;

	while (true)
	{
		std::cout << "Enter (add,subtract,scale,length,normalize) or exit: ";
		std::cin >> enter;

		if (enter == "exit")
		{
			break;
		}
		else if (enter == "add")
		{
			std::cout << "Enter first vector (x,y): " << std::endl;
			std::cin >> a.x >> a.y;

			std::cout << "Enter second vector (x,y): " << std::endl;
			std::cin >> b.x >> b.y;

			vec result = add(a, b);
			std::cout << "Result: ";
			result.conclusion();
		}
		else if (enter == "subtract")
		{
			std::cout << "Enter first vector (x,y): " << std::endl;
			std::cin >> a.x >> a.y;

			std::cout << "Enter second vector (x,y): " << std::endl;
			std::cin >> b.x >> b.y;

			vec result = subtract(a, b);
			std::cout << "Result: ";
			result.conclusion();
		}
		else if (enter == "scale")
		{
			std::cout << "Enter vector (x,y): " << std::endl;
			std::cin >> a.x >> a.y;

			std::cout << "Enter secalar: " << std::endl;
			std::cin >> scalar;

			vec result = scale(a, scalar);
			std::cout << "Result: ";
			result.conclusion();
		}
		else if (enter == "length")
		{
			std::cout << "Enter vector (x,y): " << std::endl;
			std::cin >> a.x >> a.y;
			
			double result = length(a);
			std::cout << "Length: " << result << std::endl;
		}
		else if (enter == "normalize")
		{
			std::cout << "Enter vector (x,y): " << std::endl;
			std::cin >> a.x >> a.y;

			vec result = normalize(a);
			std::cout << "Result: ";
			result.conclusion();
		}
		else
		{
			std::cout << "Error, no such command!" << std::endl;
		}
	}
	return 0;
}