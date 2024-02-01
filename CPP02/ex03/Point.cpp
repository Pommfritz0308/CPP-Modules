#include "Point.hpp"

Point::Point() : x(0), y(0)
{
	std::cout << "Default constructor called\n";
}

Point::Point(const float x, const float y) : x(x), y(y)
{
	std::cout << "Point constructor called\n";
}

Point::Point(const Point &old) : x(old.x), y(old.y)
{
	std::cout << "Copy constructor called\n";
}

Point& Point::operator= (const Point &p)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &p)
	{
		static_cast<Fixed>(x) = p.x;
		static_cast<Fixed>(y) = p.y;
	}
	return *this;
}

Point::~Point()
{
	std::cout << "Destructor called\n";
}

Fixed Point::getX(void) const
{
	return (x);
}

Fixed Point::getY(void) const
{
	return (y);
}
