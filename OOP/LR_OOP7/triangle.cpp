//
//  triangle.cpp
//  lab7
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
#include"triangle.h"

triangle::triangle(const std::array<vertex, 3>& vertices) : vertices_(vertices) {}



void triangle::setColor(std::vector<int> color) {
    for (int i = 0; i < 3; i++) {
        color_.push_back(color[i]);
    }
}

void triangle::render(const sdl::renderer& renderer) const {
    renderer.set_color(color_[0], color_[1], color_[2]);
    for (int32_t i = 0; i < 3; ++i) {
        renderer.draw_line(vertices_[i].x, vertices_[i].y,
            vertices_[(i + 1) % 3].x, vertices_[(i + 1) % 3].y);
    }

}

void triangle::save(std::ostream& os) const {
    os << "triangle\n";
    for (int32_t i = 0; i < 3; ++i) {
        os << vertices_[i].x << ' ' << vertices_[i].y << '\n';
    }
    os << color_[0] << ' ' << color_[1] << ' ' << color_[2] << '\n';
}




std::unique_ptr<figure> triangle_builder::add_vertex(const vertex& v) {
    vertices_[n_] = v;
    n_ += 1;
    if (n_ != 3) {
        return nullptr;
    }
    return std::make_unique<triangle>(vertices_);
}

std::string triangle_builder::getType() {
    return "triangle";
}