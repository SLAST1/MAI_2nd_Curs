//
//  octagon.cpp
//  lab3
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
#include "octagon.h"
#include <cmath>

Octagon::Octagon() : A{ 0, 0 }, B{ 0, 0 }, C{ 0, 0 }, D{ 0, 0 }, E{ 0, 0 }, F{ 0, 0 }, G{ 0, 0 }, H{ 0, 0 }  {}

Octagon::Octagon(std::istream& in) {
	in >> A >> B >> C >> D >> E >> F >> G >> H;
}


double Octagon::area() const {
	return 0.5* abs(A.X() * B.Y() + B.X() * C.Y() + C.X() * D.Y() + D.X() * E.Y() + E.X() * F.Y() + F.X() * G.Y() + G.X() * H.Y() + H.X() * A.Y()
		- B.X() * A.Y() - C.X() * B.Y() - D.X() * C.Y() - E.X() * D.Y() - F.X() * E.Y() - G.X() * F.Y() - H.X() * G.Y() - A.X() * H.Y());
}

Point Octagon::center() const {
	return Point{ (A.X() + B.X() + C.X() + D.X() + E.X() + F.X() + G.X() + H.X()) / 8, (A.Y() + B.Y() + C.Y() + D.Y() + E.Y() + F.Y() + G.Y() + H.Y()) / 8 };
}

std::ostream& Octagon::print(std::ostream& out) const {
	out << A << " " << B << " " << C << " " << D << " " << E << " " << F << " " << G << " " << H;
	return out;
}