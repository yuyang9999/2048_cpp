//
// Created by dzxxy on 2023-07-15.
//

#include "utility.h"
#include <random>
#include <cassert>

using namespace CORE;

Utility& Utility::getInstance() {
    static Utility* instance = nullptr;
    if (!instance) {
        instance = new Utility();
    }
    return *instance;
}


int Utility::randomInRange(int start, int end) {
    assert(start < end);
    if (end - start == 1) {
        return start;
    }
    int range = end - start;
    int randVal = rand() % range;

    return randVal + start;
}

Utility::Utility() {
    srand(0);
}


