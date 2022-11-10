//
//  money.cpp
//  lab2
//  Variant 8
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
#include "money.h"

unsigned long long Money::roub_get(const Money& a) {
    return a.roub;
}

uint16_t Money::cop_get(const Money& a) {
    return a.cop;
}
void Money::get(std::istream& is) {
    unsigned long long temp_roub; 
    uint16_t temp_cop;
    char temp;
    is >> temp_roub >> temp >> temp_cop;
    this->roub = temp_roub;
    this->cop = temp_cop;
} 

void Money::show(std::ostream& os) const {
    os << roub << ",";
    if(cop <= 0) {
        os << "00" << std::endl;
    }
    else os << cop << std::endl;
}


Money Money::operator+(const Money& a2) {
    Money temp;
    temp.roub = this->roub + a2.roub;
    temp.cop = this->cop + a2.cop;
    if(temp.cop >= 100) {
        temp.roub++;
        temp.cop -= 100;
    }
    return temp;
}

Money Money::operator-(const Money& a2) {
    Money temp;
    temp.roub = this->roub - a2.roub;
    if(this->cop < a2.cop) {
        temp.roub--;
        this->cop += 100;
        temp.cop = this->cop - a2.cop;
        this->cop -= 100;
    }
    else temp.cop = this->cop - a2.cop;
    return temp;
}

double Money::operator/(const Money& a2) {
    double temp, a, b;
    a = ((this->roub * 100) + this->cop);
    b = ((a2.roub * 100) + a2.cop);
    temp = a / b;
    return temp;
}

Money Money::operator/(double arg) {
    Money temp;
    double tempN;
    tempN = (((this->roub * 100) + this->cop) / arg) / 100;
    temp.roub = (int)tempN;
    temp.cop = (tempN - (int)tempN) * 100;
    return temp;
}

Money Money::operator*(double arg) {
    Money temp;
    double tempN;
    tempN = (((this->roub * 100) + this->cop) * arg);
    temp.roub = (int)(tempN / 100);
    temp.cop = (tempN / 100 - (int)(tempN / 100)) * 100;
    return temp;
}

bool Money::operator<(const Money& a2) {
    return (this->roub < a2.roub || (this->roub == a2.roub && this->cop < a2.cop));
}

bool Money::operator>(const Money& a2) {
    return (this->roub > a2.roub || (this->roub == a2.roub && this->cop > a2.cop));
}

bool Money::operator<=(const Money& a2) {
    return (this->roub <= a2.roub && this->cop <= a2.cop);
}

bool Money::operator>=(const Money& a2) {
    return (this->roub >= a2.roub && this->cop >= a2.cop);
}

bool Money::operator==(const Money& a2) {
    return (this->roub == a2.roub && this->cop == a2.cop);
}

bool Money::operator!=(const Money& a2) {
    return (this-> roub != a2.roub || this->cop !=a2.cop);
}

long double operator""_toCop(long double cop) {
    return (cop / 100);
}

std::ostream& operator<<(std::ostream& os, const Money& a2) {
    a2.show(os);
    return os;
}

std::istream& operator>>(std::istream& is, Money& a) {
    a.get(is);
    return is;
}