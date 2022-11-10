//
//  main.cpp
//  lab1
//  Variant 19
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 18.09.2020.
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//

#include <iostream>
#include <string>
#include "adress.hpp"

void writeInfo()
{
    std::cout << "Лабораторная работа №1\nСтудент: Пивницкий Даниэль\nГруппа: М8о-206Б-19\n\n";
    std::cout << "Создать класс Address для работы с адресами домов.\n";
    std::cout << "Адрес должен состоять из строк с названием города и улицы и чисел с номером дома и квартиры.\n";
    std::cout << "Реализовать операции сравнения адресов, а также операции проверки принадлежности адреса к улице и городу.\n";
    std::cout << "В операциях не должен учитываться регистр строки.\n";
    std::cout << "Так же необходимо сделать операцию, которая возвращает истину если два адреса находятся по соседству.\n";
    std::cout << "(на одной улице в одном городе и дома стоят подряд)\n\n";
}

signed main()
{
    writeInfo();
    std::string city, street;
    unsigned int house = 0, flat = 0;
    std::cout << "*Первый адрес*\n";
    std::cout << "Введите город: ";
    std::cin >> city;
    std::cout << "Введите улицу: ";
    std::cin >> street;
    std::cout << "Введите номер дома: ";
    std::cin >> house;
    std::cout << "Введите номер квартиры: ";
    std::cin >> flat;
    Adress a = Adress(city, street, house, flat);
    house = 0, flat = 0;
    std::cout << "*Второй адрес*\n";
    std::cout << "Введите город: ";
    std::cin >> city;
    std::cout << "Введите улицу: ";
    std::cin >> street;
    std::cout << "Введите номер дома: ";
    std::cin >> house;
    std::cout << "Введите номер квартиры: ";
    std::cin >> flat;
    Adress b = Adress(city, street, house, flat);
    std::cout << std::endl;
    if (house * flat == 0){
        std::cout << "Неправильный ввод!\n"; //проверка чтобы номер дома вводили числом
        return -1;
    }
    std::cout << "Один и тот же адрес? " << (Adress::IsEqual(a, b) ? "Да" : "Нет") << "\n";
    std::cout << "Одинаковый город и улица? " << (Adress::IsInCity(a, b.GetCity(), b.GetStreet()) ? "Да" : "Нет") << "\n";
    std::cout << "Соседи? " << (Adress::Neighbors(a, b) ? "Да" : "Нет") << "\n";
    return 0;
}
