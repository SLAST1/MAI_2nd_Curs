//
//  factory.h
//  lab8
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
#ifndef FACTORY_H
#define FACTORY_H

#include <iostream>
#include "figure.h"

namespace factory {

    class Factory {
    public:
        std::shared_ptr<figures::Figure> FigureCreate(std::istream& is) const {
            std::string type;
            std::cin >> type;
            if (type == "hexagon") {
                return std::shared_ptr<figures::Figure>(new figures::Hexagon(is));
            }
            else if (type == "octagon") {
                return std::shared_ptr<figures::Figure>(new figures::Octagon(is));
            }
            else if (type == "triangle") {
                return std::shared_ptr<figures::Figure>(new figures::Triangle(is));
            }
            throw std::logic_error("Wrong. Figures: hexagon, octagon, triangle");
        }
    };
}
#endif
