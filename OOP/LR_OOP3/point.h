//
//  point.h
//  lab3
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
public:
	Point();
	Point(double x, double y);
	double X() const;
	double Y() const;
	friend std::ostream& operator<< (std::ostream& out, const Point& p);
	friend std::istream& operator>> (std::istream& in, Point& p);
private:
	double x;
	double y;
};
#endif
