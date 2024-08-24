#include "random_fill.hpp"

#include <algorithm>
#include <functional>
#include <iostream>
#include <random>

#include "sorting_algos.hpp"

static std::vector<int> create_random_data(const size_t array_size) {
    std::vector<int> tmp(array_size);
    std::generate(std::begin(tmp), std::end(tmp), std::bind(std::uniform_int_distribution<int>{}, std::mt19937({std::random_device{}()})));
    return tmp;
}

void init_arrays(All_Values &arrays, const size_t array_size) {
    const std::vector<int> random_vector = create_random_data(array_size);
    for(size_t ii = 0; ii < static_cast<size_t>(Sort_Type::Total_Sorts); ii++) {
        arrays[ii] = random_vector;
    }
}