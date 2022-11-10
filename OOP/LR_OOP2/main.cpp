//
//  main.cpp
//  lab2
//  Variant 8
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
/*
Создать класс Money для работы с денежными суммами. 
Сумма денег должна быть представлено двумя полями: типа unsigned long long для рублей и типа unsigned char – для копеек. 
Дробная часть (копейки) при выводе на экран должна быть отделена от целой части запятой. 
Реализовать сложение сумм, вычитание, деление сумм, деление суммы на дробное число, умножение на дробное число и операции сравнения.
Операции сложения, вычитания, умножения, деления, сравнения (на равенство, больше и меньше) должны быть выполнены в виде перегрузки операторов. 
Необходимо реализовать пользовательский литерал для работы с константами типа Money.
*/
#include <iostream>
#include "money.h"

#define UNUSED(variable) (void)variable

int main(int argc, char** argv) {
    
    Money a1;
    Money a2;
    float arg;

    std::cout << "First summ:" << std::endl;
    //a1.get(std::cin);
    std::cin >> a1;
    std::cout << "Second summ:" << std::endl;
    //a2.get(std::cin);
    std::cin >> a2;
    std::cout << "Number to div and multiply" << std::endl;
    std::cin >> arg;
    if(arg == 0){
        std::cout << "cannot be divided by zero" << std::endl;
        return 0;
    }
    std::cout << std::endl;
    
    //a1.show(std::cout);
    std::cout << a1;
    //a2.show(std::cout);
    std::cout << a2;

    //(a1 + a2).show(std::cout);
    std::cout << a1 + a2;

    //(a1 - a2).show(std::cout);
    std::cout << a1 - a2;

    std::cout << a1 / a2 << std::endl;

    //(a1 / arg).show(std::cout);
    std::cout << a1 / arg;

    //(a1 * arg).show(std::cout);
    std::cout << a1 * arg << std::endl;

    if(a1 < a2) std::cout << "<:" << std::endl;
    else std::cout << "<: false" << std::endl;

    if(a1 > a2) std::cout << ">: true" << std::endl;
    else std::cout << ">: false" << std::endl;

    if(a1 <= a2) std::cout << "<=: true" << std::endl;
    else std::cout << "<=: false" << std::endl;

    if(a1 >= a2) std::cout << ">=: true" << std::endl;
    else std::cout << ">=: false" << std::endl;

    if(a1 == a2) std::cout << "==: true" << std::endl;
    else std::cout << "==: false" << std::endl;

    if(a1 != a2) std::cout << "!=: true" << std::endl;
    else std::cout << "!=: false" << std::endl;


    long double sum;
    std::cout << "insert summ (+50 cops): ";
    std::cin >> sum;
    std::cout << sum + 50.00_toCop << std::endl;

    UNUSED(argc);
    UNUSED(argv);

    return 0;
}

// перегрузить оператор вывода