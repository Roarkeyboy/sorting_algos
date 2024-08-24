#pragma once

#include "namespaces.hpp"

enum class Sort_Type : size_t {
    Bubble_Sort = 0,
    Selection_Sort,
    Insertion_Sort,
    Quick_Sort,
    Merge_Sort,
    Shell_Sort,
    Heap_Sort,

    Total_Sorts
};

class Sorter {
public:
    Sorter(const All_Values &all_values_in);

    void bubble_sort(std::vector<int> &values);
    void selection_sort(std::vector<int> &values);
    void insertion_sort(std::vector<int> &values);
    void quick_sort(std::vector<int> &values, const size_t low, const size_t high);
    void merge_sort(std::vector<int> &values, const size_t low, const size_t high);
    void shell_sort(std::vector<int> &values);
    void heap_sort(std::vector<int> &values);

    void timed_bubble_sort(std::vector<int> &values);
    void timed_selection_sort(std::vector<int> &values);
    void timed_insertion_sort(std::vector<int> &values);
    void timed_quick_sort(std::vector<int> &values, const size_t low, const size_t high);
    void timed_merge_sort(std::vector<int> &values, const size_t low, const size_t high);
    void timed_shell_sort(std::vector<int> &values);
    void timed_heap_sort(std::vector<int> &values);

    void run_all_timed_sorts();
    void run_insertion_sort_with_print(std::vector<int> &values);

private:
    All_Values all_values;
};
