#ifndef SORTING_ALGOS_HPP
#define SORTING_ALGOS_HPP

#include <vector>

enum class Sort_Type : size_t {
    Bubble_Sort = 0,
    Selection_Sort,
    Insertion_Sort,
    Quick_Sort,
    Merge_Sort,
    Shell_Sort,
    Heap_Sort,
};

void print_array(std::vector<int> & array);
void bubble_sort(std::vector<int> & array);
void timed_bubble_sort(std::vector<int> & array);
void selection_sort(std::vector<int> & array);
void timed_selection_sort(std::vector<int> & array);
void insertion_sort(std::vector<int> & array);
void timed_insertion_sort(std::vector<int> & array);
void quick_sort(std::vector<int> & arr, size_t low, size_t high);
void timed_quick_sort(std::vector<int> & arr, size_t low, size_t high);
void merge_sort(std::vector<int> & array, size_t low, size_t high);
void timed_merge_sort(std::vector<int> & array, size_t low, size_t high);
void shell_sort(std::vector<int> & array);
void timed_shell_sort(std::vector<int> & array);
void heap_sort(std::vector<int> & array);
void timed_heap_sort(std::vector<int> & array);

void run_all_timed_sorts(std::vector<std::vector<int>> & arrays);

#endif //SORTING_ALGOS_HPP