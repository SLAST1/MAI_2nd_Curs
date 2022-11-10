#include "point.h"
#include <cmath>

Point::Point() : x{ 0 }, y{ 0 }
{}

Point::Point(double x, double y) : x{ x }, y{ y }
{}

double Point::X() const
{
	return x;
}

double Point::Y() const
{
	return y;
}

std::ostream& operator<< (std::ostream& out, const Point& p)
{
	out << "(" << p.X() << ";" << p.Y() << ")";
	return out;
}


std::istream& operator>> (std::istream& in, Point& p)
{
	in >> p.x >> p.y;
	return in;
}