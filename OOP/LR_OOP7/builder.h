//
//  builder.h
//  lab7
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
#ifndef D_BUILDER_H
#define D_BUILDER_H 1

#include "figure.h"

struct builder {
	virtual std::unique_ptr<figure> add_vertex(const vertex& v) = 0;
	virtual std::string getType() = 0;

	virtual ~builder() = default;

};

#endif //!D_BUILDER_H