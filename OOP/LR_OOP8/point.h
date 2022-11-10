//
//  point.h
//  lab8
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
#ifndef OOP_LAB7_POINT_H
#define OOP_LAB7_POINT_H

#include <iostream>


struct point {
    point() : x(0), y(0) {}
    point(double a, double b) : x(a), y(b) {}
    double x;
    double y;
};


std::istream& operator>>(std::istream& is, point& p) {
    is >> p.x >> p.y;
    return is;
}


std::ostream& operator<<(std::ostream& os, point p) {
    os << '(' << p.x << ' ' << p.y << ')';
    return os;
}

#endif
