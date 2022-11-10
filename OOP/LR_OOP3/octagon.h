//
//  octagon.h
//  lab3
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
#ifndef OCTAGON_H
#define OCTAGON_H

#include "figure.h"
#include "point.h"

class Octagon : public Figure {
public:
	Octagon();
	Octagon(std::istream& in);
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
	Point G;
	Point H;
};
#endif