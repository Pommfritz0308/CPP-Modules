#include <iostream>
#include "Point.hpp"

int main( void )
{
	Point p = Point(3, 0.5f);
	Point a = Point(0, 0);
	Point b = Point(0, 3);
	Point c = Point(4, 0);

	if (bsp(a, b, c, p))
		std::cout << "Point is inside the triangle\n";
	else
		std::cout << "Point is outside the triangle\n";
	return 0;
}
