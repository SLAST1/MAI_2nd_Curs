//
//  loader.cpp
//  lab7
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
#include"loader.h"

std::vector<std::unique_ptr<figure>> loader::load(std::ifstream& is) {
        std::string figure_name;
        std::vector<std::unique_ptr<figure>> figures;
        while (is >> figure_name) {
            vertex v;
            if (figure_name == std::string("curve_line")) {
                std::vector<vertex> vertices;
                int count_v;
                is >> count_v;
                for (int i = 0; i < count_v; ++i) {
                    is >> v.x >> v.y;
                    vertices.push_back(v);
                }
                struct color buffcolor {};
                is >> buffcolor.r >> buffcolor.g >> buffcolor.b;
            }

            else if (figure_name == std::string("quadrangle")) {
                std::array<vertex, 4> vertices;
                for (int i = 0; i < 4; ++i) {
                    is >> v.x >> v.y;
                    vertices[i] = v;
                }
                struct color buffcolor {};
                is >> buffcolor.r >> buffcolor.g >> buffcolor.b;

                figures.emplace_back(std::make_unique<quadrangle>(vertices));
                (*figures[figures.size() - 1]).set_color(buffcolor);
            }
            else if (figure_name == std::string("circle")) {
                std::vector<vertex> vertices(2);
                is >> vertices[0] >> vertices[1];
                struct color buffcolor {};
                is >> buffcolor.r >> buffcolor.g >> buffcolor.b;

                figures.emplace_back(std::make_unique<circle>(vertices));
                (*figures[figures.size() - 1]).set_color(buffcolor);
            }

            else if (figure_name == std::string("triangle")) {
                std::array<vertex, 3> vertices;
                for (int i = 0; i < 3; ++i) {
                    is >> v.x >> v.y;
                    vertices[i] = v;
                }
                struct color buffcolor {};
                is >> buffcolor.r >> buffcolor.g >> buffcolor.b;

                figures.emplace_back(std::make_unique<triangle>(vertices));
                (*figures[figures.size() - 1]).set_color(buffcolor);
            }
            else if (figure_name == std::string("polygon")) {
                std::vector<vertex> vertices;
                int count_v;
                is >> count_v;
                for (int i = 0; i < count_v; ++i) {
                    is >> v.x >> v.y;
                    vertices.push_back(v);
                }
                struct color buffcolor {};
                is >> buffcolor.r >> buffcolor.g >> buffcolor.b;

                figures.emplace_back(std::make_unique<curve_line>(vertices));
                (*figures[figures.size() - 1]).set_color(buffcolor);
            }
            else if (figure_name == std::string("hexagon")) {
                std::array<vertex, 6> vertices;
                for (int i = 0; i < 6; ++i) {
                    is >> v.x >> v.y;
                    vertices[i] = v;
                }
                struct color buffcolor {};
                is >> buffcolor.r >> buffcolor.g >> buffcolor.b;

                figures.emplace_back(std::make_unique<hexagon>(vertices));
                (*figures[figures.size() - 1]).set_color(buffcolor);
            }
        }
        return figures;
    }
    loader::~loader() = default;
