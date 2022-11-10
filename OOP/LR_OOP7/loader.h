//
//  loader.h
//  lab7
//  Variant 15
//  M8о-206Б-19
//  Created by Daniel Pivnitskiy on 10.10.2020.
//  github.com/SLAST1
//  Copyright © 2020 Daniel Pivnitskiy. All rights reserved.
//
#ifndef LOADER_H
#define LOADER_H


#include <array>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
#include <stack>
#include "figure.h"

struct loader {

    std::vector<std::unique_ptr<figure>> load(std::ifstream& is);
       
    ~loader();
};
#endif