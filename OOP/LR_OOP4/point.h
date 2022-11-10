//
//  point.h
//  lab4
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
#ifndef OOP_EXERCISE_04_POINT_H
#define OOP_EXERCISE_04_POINT_H

#include <iostream>
#include <type_traits>
#include <cmath>


template<class T>
struct point {
	T x;
	T y;
	point<T>& operator=(point<T> A);
};

template<class T>
std::istream& operator>>(std::istream& is, point<T>& p) {
	is >> p.x >> p.y;
	return is;
}

template<class T>
std::ostream& operator<<(std::ostream& os, point<T> p) {
	os << '(' << p.x << ' ' << p.y << ')';
	return os;
}

template<class T>
point<T> operator+(const point<T>& A, const point<T>& B) {
	point<T> res;
	res.x = A.x + B.x;
	res.y = A.y + B.y;
	return res;
}

template<class T>
point<T>& point<T>::operator=(const point<T> A) {
	this->x = A.x;
	this->y = A.y;
	return *this;
}

template<class T>
point<T> operator+=(point<T>& A, const point<T>& B) {
	A.x += B.x;
	A.y += B.y;
	return A;
}

template<class T>
point<T> operator/=(point<T>& A, const double B) {
	A.x /= B;
	A.y /= B;
	return A;
}

template<class T>
double point_length(point<T>& A, point<T>& B) {
	double res = sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
	return res;
}

template<class T>
struct is_point : std::false_type {};

template<class T>
struct is_point<point<T>> : std::true_type {};


#endif 