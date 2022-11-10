//
//  main.cpp
//  lab3
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
/*
Создать программу, которая позволяет:
Вводить из стандартного ввода std::cin фигуры, согласно варианту задания.
(6-угольник, 8-угольник,Треугольник)
Сохранять созданные фигуры в динамический массив std::vector<Figure*>
Вызывать для всего массива общие функции (1-3 см. выше).
Т.е. распечатывать для каждой фигуры в массиве геометрический центр, координаты вершин и площадь.
Необходимо уметь вычислять общую площадь фигур в массиве.
Удалять из массива фигуру по индексу;
*/

#include <iostream>
#include "figure.h"
#include "triangle.h"
#include "octagon.h"
#include "hexagon.h"
#include <vector>
#include <string>

void read_figt(std::vector<Figure*>& fig)
{
    int figt;
    Figure* f = nullptr;

    std::cout << "Fig types: 1 - triangle; 2 - hexagon; 3 - octagon\n";
    std::cin >> figt;
    if (figt == 1) {
        f = new Triangle(std::cin); 
    }
    else if (figt == 2) {
        f = new Hexagon(std::cin);
    }
    else if (figt == 3) {
    f = new Octagon(std::cin);
    
}else{
    std::cout << "Wrong. Try 1 - triangle, 2 - hexagon or 3 - octagon\n";
        }
    fig.push_back(dynamic_cast<Figure*>(f));
    }

    
int main() {
    unsigned int index;
    double Tarea = 0;
    std::string operation;
    std::vector<Figure*> fig;
    
    std::cout << "Operations: add / delete / out / quit\n";

    while (std::cin >> operation) {
        if (operation == "add") {
            read_figt(fig);
        }
        else if (operation == "delete") {
            std::cin >> index;
            delete fig[index];
            for (; index < fig.size() - 1; ++index) {
                fig[index] = fig[index + 1];
            }
            fig.pop_back();
        }
        else if (operation == "out") {
            Tarea = 0;
            for (unsigned int i = 0; i < fig.size(); i++) {
                std::cout << i << ":\n";
                std::cout << "Area: " << fig[i]->area() << std::endl;
                std::cout << "Center: " << fig[i]->center() << std::endl;
                std::cout << "Coordinates: ";
                fig[i]->print(std::cout);
                std::cout << std::endl;
                Tarea += fig[i]->area();
            }
            std::cout << "Total area: " << Tarea << std::endl;
        }
        else if (operation == "quit") {
            for (unsigned int i = 0; i < fig.size(); ++i) {
                delete fig[i];
            }
            return 0;
        }
        else {
            std::cout << "Wrong. Operations: add / delete / out / quit\n";
        }
    }
}