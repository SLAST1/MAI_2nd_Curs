//
//  triangle.h
//  lab3
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"
#include "point.h"

class Triangle : public Figure {
public:
	Triangle();
	Triangle(std::istream& in);
	double area() const override;
	Point center() const override;
	std::ostream& print(std::ostream& out) const override;
private:
	Point A;
	Point B;
	Point C;
};
#endif
