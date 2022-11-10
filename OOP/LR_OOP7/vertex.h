//
//  vertex.h
//  lab7
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
#ifndef D_VERTEX_H
#define D_VERTEX_H 1

#include <memory>
#include <fstream>
#include <iostream>

struct vertex {
	int32_t x, y;

};

inline std::istream& operator>> (std::istream& is, vertex& p) {
	is >> p.x >> p.y;
	return is;
}

#endif // !D_VERTEX_H
