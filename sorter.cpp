#include <iostream>
#include <utility>

#include "random_fill.hpp"
#include "sorting_algos.hpp"

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cerr << "Enter the number of values you want to fill the sortable arrays with\n";
        return EXIT_FAILURE;
    }

    size_t array_size = 0;
    try {
        array_size = std::stoull(argv[1]);
    }
    catch(const std::exception &ex) {
        std::cerr << "Failed to parse input number of values: " << ex.what() << '\n';
        return EXIT_FAILURE;
    }

    if(array_size == 0 || array_size == 1) {
        std::cerr << "Enter the number of values you want to fill the sortable arrays with\n";
        return EXIT_FAILURE;
    }

    All_Values all_values(std::to_underlying(Sort_Type::Total_Sorts));
    init_arrays(all_values, array_size);

    Sorter::run_all_timed_sorts(all_values);
    Sorter::sort(all_values, Sort_Type::Bubble_Sort, Sort_Timed::Timed);

    return EXIT_SUCCESS;
}