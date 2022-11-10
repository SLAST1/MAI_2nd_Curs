//
//  figures.h
//  lab4
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
#ifndef OOP_EXERCISE_04_FIGURES_H
#define OOP_EXERCISE_04_FIGURES_H

template<class T>
void figures(std::istream& is, std::ostream& os) {
	if constexpr (has_dots<T>::value) {
		T object(is);
		printout(object, os);
		os << std::endl;
		os << area(object) << std::endl;
		os << center(object) << std::endl;
	}
	else if constexpr (is_figurelike_tuple<T>::value) {
		size_t s;
		os << "enter number of angles: ";
		is >> s;
		switch (s) {
		case 3: {
			point<double> fig[3];
			for (auto& i : fig) {
				is >> i;
			}
			auto [a, b, c] = fig;
			auto object = std::make_tuple(a, b, c);
			printout(object, os);
			os << std::endl;
			os << area(object) << std::endl;
			os << center(object) << std::endl;
			break;
		}
		
		case 6: {
			point<double> fig[6];
			for (auto& i : fig) {
				is >> i;
			}
			auto [a, b, c, d, e, f] = fig;
			auto object = std::make_tuple(a, b, c, d, e, f);
			printout(object, os);
			os << std::endl;
			os << area(object) << std::endl;
			os << center(object) << std::endl;
			break;
		}

		case 8: {
			point<double> fig[8];
			for (auto& i : fig) {
				is >> i;
			}
			auto [a, b, c, d, e, f, g, h] = fig;
			auto object = std::make_tuple(a, b, c, d, e, f, g, h);
			printout(object, os);
			os << std::endl;
			os << area(object) << std::endl;
			os << center(object) << std::endl;
			break;
		}
		default:
			throw std::logic_error("incorrect number of angles, try 3, 4 or 8");

		}


	}
	
}

#endif 
