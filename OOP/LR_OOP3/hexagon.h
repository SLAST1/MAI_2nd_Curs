//
//  hexagon.h
//  lab3
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
#ifndef HEXAGON_H
#define HEXAGON_H

#include "figure.h"
#include "point.h"

class Hexagon : public Figure {
public:
	Hexagon();
	Hexagon(std::istream& in);
	double area() const override;
	Point center() const override;
	std::ostream& print(std::ostream& out) const override;
private:
	Point A;
	Point B;
	Point C;
	Point D;
	Point E;
	Point F;
};
#endif