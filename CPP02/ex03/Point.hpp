#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"


class Point
{
	private:

		const Fixed x;
		const Fixed y;

	public:

		Point();
		Point(const float x, const float y);
		Point(const Point &old);
		Point& operator= (const Point &p);
		~Point();
		Fixed getX(void) const;
		Fixed getY(void) const;

};

bool bsp(const Point& a, const Point& b, const Point& c, const Point& point);

#endif
