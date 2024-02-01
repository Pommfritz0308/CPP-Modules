#include "Point.hpp"

bool bsp(const Point& a, const Point& b, const Point& c, const Point& point)
{
	Fixed ABx = b.getX() - a.getX();
	Fixed ABy = b.getY() - a.getY();
	Fixed BCx = c.getX() - b.getX();
	Fixed BCy = c.getY() - b.getY();
	Fixed CAx = a.getX() - c.getX();
	Fixed CAy = a.getY() - c.getY();

	Fixed APx = point.getX() - a.getX();
	Fixed APy = point.getY() - a.getY();
	Fixed BPx = point.getX() - b.getX();
	Fixed BPy = point.getY() - b.getY();
	Fixed CPx = point.getX() - c.getX();
	Fixed CPy = point.getY() - c.getY();

	Fixed crossAB = ABx.toFloat() * APy.toFloat() - ABy.toFloat() * APx.toFloat();
	Fixed crossBC = BCx.toFloat() * BPy.toFloat() - BCy.toFloat() * BPx.toFloat();
	Fixed crossCA = CAx.toFloat() * CPy.toFloat() - CAy.toFloat() * CPx.toFloat();

	if (crossAB.toFloat() * crossBC.toFloat() > 0 && crossBC.toFloat() * crossCA.toFloat() > 0)
		return (true);
	return (false);
}
