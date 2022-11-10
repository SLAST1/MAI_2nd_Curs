//
//  figure.h
//  lab7
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
#ifndef D_FIGURE_H
#define D_FIGURE_H 1

#include "vertex.h"

#include "sdl.h"
#include <array>
#include <vector>
#include <memory>
//#include <iostream>
//#include <fstream>
#include <string>


struct figure {
	virtual void render(const sdl::renderer& renderer) const = 0;
	virtual void save(std::ostream& os) const = 0;
	virtual void setColor(std::vector<int> color) = 0;
	virtual ~figure() = default;

};

#endif // !D_FIGURE_H