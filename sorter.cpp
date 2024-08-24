#include <iostream>

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

    All_Values arrays(static_cast<size_t>(Sort_Type::Total_Sorts));

    init_arrays(arrays, array_size);
    run_all_timed_sorts(arrays);

    return EXIT_SUCCESS;
}