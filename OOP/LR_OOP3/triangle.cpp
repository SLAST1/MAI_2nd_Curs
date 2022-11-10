//
//  triangle.cpp
//  lab3
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
#include "triangle.h"
#include <cmath>

Triangle::Triangle() : A{ 0, 0 }, B{ 0, 0 }, C{ 0, 0 } {}

Triangle::Triangle(std::istream& in) {
	in >> A >> B >> C;
}


double Triangle::area() const {
	return 0.5 * abs(A.X() * B.Y() + B.X() * C.Y() + C.X() * A.Y() - B.X() * A.Y() - C.X() * B.Y() - A.X() * C.Y());
}

Point Triangle::center() const
{
	return Point{ (A.X() + B.X() + C.X()) / 3, (A.Y() + B.Y() + C.Y()) / 3 };
}

std::ostream& Triangle::print(std::ostream& out) const
{
	out << A << " " << B << " " << C;
	return out;
}