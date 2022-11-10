//
//  hexagon.cpp
//  lab3
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
#include "hexagon.h"
#include <cmath>

Hexagon::Hexagon() : A{ 0, 0 }, B{ 0, 0 }, C{ 0, 0 }, D{ 0, 0 }, E{ 0, 0 }, F{ 0, 0 } {}

Hexagon::Hexagon(std::istream& in) {
	in >> A >> B >> C >> D >> E >> F;
}


double Hexagon::area() const {
	return 0.5 * abs(A.X() * B.Y() + B.X() * C.Y() + C.X() * D.Y() + D.X() * E.Y() + E.X() * F.Y() + F.X() * A.Y()
		- B.X() * A.Y() - C.X() * B.Y() - D.X() * C.Y() - E.X() * D.Y() - F.X() * E.Y() - A.X() * F.Y());
}

Point Hexagon::center() const {
	return Point{ (A.X() + B.X() + C.X() + D.X() + E.X() + F.X()) / 6, (A.Y() + B.Y() + C.Y() + D.Y() + E.Y() + F.Y()) / 6 };
}

std::ostream& Hexagon::print(std::ostream& out) const {
	out << A << " " << B << " " << C << " " << D << " " << E << " " << F;
	return out;
}