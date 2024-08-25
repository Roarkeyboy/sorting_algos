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

enum class Sort_Timed : bool {
    Untimed = false,
    Timed = true,
};

class Sorter {
public:
    static void sort(All_Values &all_values_in, const Sort_Type sort_type, const Sort_Timed = Sort_Timed::Untimed);
    static void run_all_timed_sorts(All_Values &all_values);

private:
    static void bubble_sort(std::vector<int> &values);
    static void selection_sort(std::vector<int> &values);
    static void insertion_sort(std::vector<int> &values);
    static void quick_sort(std::vector<int> &values, const size_t low, const size_t high);
    static void merge_sort(std::vector<int> &values, const size_t low, const size_t high);
    static void shell_sort(std::vector<int> &values);
    static void heap_sort(std::vector<int> &values);

    static void timed_bubble_sort(std::vector<int> &values);
    static void timed_selection_sort(std::vector<int> &values);
    static void timed_insertion_sort(std::vector<int> &values);
    static void timed_quick_sort(std::vector<int> &values, const size_t low, const size_t high);
    static void timed_merge_sort(std::vector<int> &values, const size_t low, const size_t high);
    static void timed_shell_sort(std::vector<int> &values);
    static void timed_heap_sort(std::vector<int> &values);
};
