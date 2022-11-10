//
//  hexagon.h
//  lab7
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
#ifndef D_HEXAGON_H
#define D_HEXAGON_H 1

#include "figure.h"
#include "builder.h"

struct hexagon : figure {
    hexagon(const std::array<vertex, 6>& vertices);
    void setColor(std::vector<int> color);

    void render(const sdl::renderer& renderer) const override;

    void save(std::ostream& os) const override;


private:
    std::array<vertex, 6> vertices_;
    std::vector<int> color_;

};

struct hexagon_builder : builder {
    std::unique_ptr<figure> add_vertex(const vertex& v);
    std::string getType();

private:
    int32_t n_ = 0;
    std::array<vertex, 6> vertices_;

};

#endif
