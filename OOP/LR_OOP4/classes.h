//
//  classes.h
//  lab4
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
#ifndef OOP_EXERCISE_04_CLASSES_H
#define OOP_EXERCISE_04_CLASSES_H

#include "point.h"
#include <type_traits>
#include <iostream>

template <class T>
class Triangle {
public:
	point<T> dots[3];
	int size = 3;
	explicit Triangle<T>(std::istream& is) {
		for (auto& dot : dots) {
			is >> dot;
		}
	}
};

template <class T>
class Hexagon {
public:
	point<T> dots[6];
	int size = 6;
	explicit Hexagon<T>(std::istream& is) {
		for (auto& dot : dots) {
			is >> dot;
		}
	}
};

template <class T>
class Octagon {
public:
	point<T> dots[8];
	int size = 8;
	explicit Octagon<T>(std::istream& is) {
		for (auto& dot : dots) {
			is >> dot;
		}
	}
};

#endif 
