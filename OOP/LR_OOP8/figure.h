//
//  figure.h
//  lab8
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
#ifndef FIGURE_H
#define FIGURE_H

#include <iostream>
#include <cmath>
#include "point.h"

namespace figures {

    enum FigureType {
        hexagon,
        octagon,
        triangle
    };

    class Figure {
    public:
        virtual std::ostream& print(std::ostream& out) const = 0;
        ~Figure() = default;
    };


    class Hexagon : public Figure {
    public:
        point A, B, C, D, E, F;

        Hexagon() : A{ 0, 0 }, B{ 0, 0 }, C{ 0, 0 }, D{ 0, 0 }, E{ 0, 0 }, F{ 0, 0 } {}

        explicit Hexagon(std::istream& is) {
            is >> A >> B >> C >> D >> E >> F;
        }

        std::ostream& print(std::ostream& os) const override {
            os << "hexagon: " << A << " " << B << " " << C << " " << D << " " << E << " " << F << std::endl;
            return os;
        }

    };


    class Octagon : public Figure {
    public:
        point A, B, C, D, E, F, G, H;

        Octagon() : A{ 0, 0 }, B{ 0, 0 }, C{ 0, 0 }, D{ 0, 0 }, E{ 0, 0 }, F{ 0, 0 }, G{ 0, 0 }, H{ 0, 0 }  {}

        explicit Octagon(std::istream& is) {
            is >> A >> B >> C >> D >> E >> F >> G >> H;
        }

        std::ostream& print(std::ostream& os) const override {
            os << "octagon: " << A << " " << B << " " << C << " " << D << " " << E << " " << F << " " << G << " " << H << std::endl;;
            return os;
        }

    };


    class Triangle : public Figure {
    public:
        point A, B, C, D;


        Triangle() : A{ 0, 0 }, B{ 0, 0 }, C{ 0, 0 } {}

        explicit Triangle(std::istream& is) {
            is >> A >> B >> C;
        }

        std::ostream& print(std::ostream& os) const override {
            os << "triangle: " << A << " " << B << " " << C << std::endl;
            return os;
        }
    };

}

#endif