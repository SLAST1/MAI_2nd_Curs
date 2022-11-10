//
//  octagon.cpp
//  lab7
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
#include"octagon.h"

octagon::octagon(const std::array<vertex, 8>& vertices) : vertices_(vertices) {}


void octagon::setColor(std::vector<int> color) {
    for (int i = 0; i < 3; i++) {
        color_.push_back(color[i]);
    }
}

void octagon::render(const sdl::renderer& renderer) const {
    renderer.set_color(color_[0], color_[1], color_[2]);
    for (int32_t i = 0; i < 8; ++i) {
        renderer.draw_line(vertices_[i].x, vertices_[i].y,
            vertices_[(i + 1) % 8].x, vertices_[(i + 1) % 8].y);
    }

}

void octagon::save(std::ostream& os) const {
    os << "octagon\n";
    for (int32_t i = 0; i < 8; ++i) {
        os << vertices_[i].x << ' ' << vertices_[i].y << '\n';
    }
    os << color_[0] << ' ' << color_[1] << ' ' << color_[2] << '\n';
}



std::unique_ptr<figure> octagon_builder::add_vertex(const vertex& v) {
    vertices_[n_] = v;
    n_ += 1;
    if (n_ != 8) {
        return nullptr;
    }
    return std::make_unique<octagon>(vertices_);
}

std::string octagon_builder::getType() {
    return "octagon";
}