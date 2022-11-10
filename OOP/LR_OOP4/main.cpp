//
//  main.cpp
//  lab4
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
/*
Разработать шаблоны классов согласно варианту задания.
Параметром шаблона должен являться скалярный тип данных задающий тип данных для оси координат.
Классы должны иметь только публичные поля. В классах не должно быть методов, только поля.
Фигуры являются фигурами вращения (равнобедренными), за исключением трапеции и прямоугольника.
Для хранения координат фигур необходимо использовать шаблон  std::pair.
*/
#include <iostream>
#include "templates.h"
#include "point.h"
#include "figures.h"
#include <vector>

int main() {
	char option = '0';
	while (option != 'q') {
		std::cout << "choose option (m for menu, q to quit): ";
		std::cin >> option;
		switch (option) {
		default:
			std::cout << "no such option, try m for menu" << std::endl;
			break;
		case 'q':
			break;
		case 'm': {
			std::cout << "1) triangle" << '\n'
				<< "2) hexagon" << '\n'
				<< "3) octagon" << '\n'
				<< "4) tuple" << '\n'
				<< "5) dop" << std::endl;
			break;
		}
		case '1': {
			figures<Triangle<double>>(std::cin, std::cout);
			break;
		}
		case '2': {
			figures<Hexagon<double>>(std::cin, std::cout);
			break;
		}
		case '3': {
			figures<Octagon<double>>(std::cin, std::cout);
			break;
		}
		case '4': {
			figures<std::tuple<point<double>>>(std::cin, std::cout);
			break;
		}
		case '5': {
			std::cout << is_ok<std::string, char*>::value << std::endl;
			std::cout << is_ok<float, int>::value << std::endl;
			std::cout << is_ok<char, std::vector < double>>::value << std::endl;
		}
		}
	}
	return 0;
}
