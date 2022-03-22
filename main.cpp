#include <iostream>
#include <string>

#include "array.hpp"
#include "sorting_algos.hpp"

int main() {
    std::cout << "Enter the size of your random array: ";

    size_t array_size = 0;
    std::cin >> array_size;

    std::vector<std::vector<int>> arrays;
    arrays.reserve(7);

    init_arrays(arrays, array_size);
    run_all_timed_sorts(arrays);

    return 0;
}