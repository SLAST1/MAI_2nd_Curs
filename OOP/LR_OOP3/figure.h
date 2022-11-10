//
//  figure.h
//  lab3
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include "point.h"

class Figure {
public:
	virtual double area() const = 0;
	virtual Point center() const = 0;
	virtual std::ostream& print(std::ostream& out) const = 0;
	virtual ~Figure() = default;
};

#endif
