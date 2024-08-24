#include "sorting_algos.hpp"

#include <chrono>
#include <iostream>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

static void print_array(std::vector<int> &values) {
    for(size_t ii = 0; ii < values.size(); ii++) {
        std::cout << values[ii] << ", ";
    }
    std::cout << '\n';
}

static constexpr void finish_timing(const auto &t1) {
    const auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1) << '\n';
}

void bubble_sort(std::vector<int> &values) {
    std::cout << "Bubble sort: \t";
    for(size_t ii = 0; ii < values.size(); ii++) {
        for(size_t jj = ii + 1; jj < values.size(); jj++) {
            if(values[jj] < values[ii]) {
                std::swap(values[ii], values[jj]);
            }
        }
    }
}

void timed_bubble_sort(std::vector<int> &values) {
    const auto t1 = std::chrono::high_resolution_clock::now();
    bubble_sort(values);
    finish_timing(t1);
}

static constexpr size_t find_smallest(std::vector<int> &values, const size_t ii) {
    int ele_small = values[ii];
    size_t position = ii;
    for(size_t jj = ii + 1; jj < values.size(); jj++) {
        if(values[jj] < ele_small) {
            ele_small = values[jj];
            position = jj;
        }
    }
    return position;
}

void selection_sort(std::vector<int> &values) {
    std::cout << "Selection sort: ";
    size_t pos;
    for(size_t ii = 0; ii < values.size(); ii++) {
        pos = find_smallest(values, ii);
        std::swap(values[ii], values[pos]);
    }
}

void timed_selection_sort(std::vector<int> &values) {
    const auto t1 = std::chrono::high_resolution_clock::now();
    selection_sort(values);
    finish_timing(t1);
}

void insertion_sort(std::vector<int> &values) {
    std::cout << "Insertion sort: ";
    for(size_t ii = 1; ii < values.size(); ii++) {
        const int temp = values[ii];
        int jj = static_cast<int>(ii - 1);
        while(jj >= 0 && temp <= values[static_cast<size_t>(jj)]) {
            values[static_cast<size_t>(jj + 1)] = values[static_cast<size_t>(jj)];
            jj--;
        }
        values[static_cast<size_t>(jj + 1)] = temp;
    }
}

void timed_insertion_sort(std::vector<int> &values) {
    const auto t1 = std::chrono::high_resolution_clock::now();
    insertion_sort(values);
    finish_timing(t1);
}

static constexpr size_t partition(std::vector<int> &values, const size_t low, const size_t high) {
    const size_t pivot = static_cast<size_t>(values[low]);
    size_t count = 0;
    for (size_t ii = low + 1; ii <= high; ii++) {
        if(static_cast<size_t>(values[ii]) <= pivot) {
            count++;
        }
    }
    // Giving pivot element its correct position
    const size_t pivot_index = low + count;
    std::swap(values[pivot_index], values[low]);
    // Sorting left and right parts of the pivot element
    size_t ii = low;
    size_t jj = high;

    while(ii < pivot_index && jj > pivot_index) {
        while(static_cast<size_t>(values[ii]) <= pivot) {
            ii++;
        }
        while(static_cast<size_t>(values[jj]) > pivot) {
            jj--;
        }
        if(ii < pivot_index && jj > pivot_index) {
            std::swap(values[ii++], values[jj--]);
        }
    }
    return pivot_index;
}

void quick_sort(std::vector<int> &values, const size_t low, const size_t high) {
    if(low < high && !values.empty()) {
        const size_t pivot = partition(values, low, high);
        if(pivot == 0) {
            return;
        }
        quick_sort(values, low, pivot - 1);
        quick_sort(values, pivot + 1, high);
    }
}

void timed_quick_sort(std::vector<int> &values, const size_t low, const size_t high) {
    const auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << "Quick sort: \t";
    quick_sort(values, low, high);
    finish_timing(t1);
}

static void merge(std::vector<int> &values, const size_t low, const size_t high, const size_t mid) {
    std::vector<int> cc(values.size());
    size_t ii = low;
    size_t kk = low;
    size_t jj = mid + 1;
    while(ii <= mid && jj <= high) {
        if(values[ii] < values[jj]) {
            cc[kk] = values[ii];
            kk++;
            ii++;
        }
        else {
            cc[kk] = values[jj];
            kk++;
            jj++;
        }
    }
    while(ii <= mid) {
        cc[kk] = values[ii];
        kk++;
        ii++;
    }
    while(jj <= high) {
        cc[kk] = values[jj];
        kk++;
        jj++;
    }
    for(ii = low; ii < kk; ii++) {
        values[ii] = cc[ii];
    }
}

void merge_sort(std::vector<int> &values, const size_t low, const size_t high) {
    if(low < high){
        //divide the array at mid and sort independently using merge sort
        const size_t mid = (low + high) / 2;
        merge_sort(values, low, mid);
        merge_sort(values, mid + 1, high);
        //merge or conquer sorted arrays
        merge(values, low, high, mid);
    }
}

void timed_merge_sort(std::vector<int> &values, const size_t low, const size_t high) {
    const auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << "Merge sort: \t";
    merge_sort(values, low, high);
    finish_timing(t1);
}

void shell_sort(std::vector<int> &values) {
    std::cout << "Shell sort: \t";
    for(size_t gap = values.size() / 2; gap > 0; gap /= 2) {
        for(size_t ii = gap; ii < values.size(); ii++) {
            //sort sub lists created by applying gap
            const size_t temp = static_cast<size_t>(values[ii]);
            size_t jj;
            for(jj = ii; jj >= gap && static_cast<size_t>(values[jj - gap]) > temp; jj -= gap) {
                values[jj] = values[jj - gap];
            }
            values[jj] = temp;
        }
    }
}

void timed_shell_sort(std::vector<int> &values) {
    const auto t1 = std::chrono::high_resolution_clock::now();
    shell_sort(values);
    finish_timing(t1);
}

// function to heapify the tree
static constexpr void heapify(std::vector<int> &values, const size_t array_size, const size_t root) {
    size_t largest = root; // root is the largest element
    const size_t ll = 2 * root + 1;
    const size_t rr = 2 * root + 2;
    // If left child is larger than root
    if(ll < values.size() && values[ll] > values[largest]) {
        largest = ll;
    }
    // If right child is larger than largest so far
    if(rr < values.size() && values[rr] > values[largest]) {
        largest = rr;
    }
    // If largest is not root
    if(largest != root) {
        //swap root and largest
        std::swap(values[root], values[largest]);
        // Recursively heapify the sub-tree
        heapify(values, array_size, largest);
    }
}

void heap_sort(std::vector<int> &values) {
    std::cout << "Heap sort: \t";
    // build heap
    for(size_t ii = values.size() / 2 - 1; ii > 0; ii--) {
        heapify(values, values.size(), ii);
    }
    // extracting elements from heap one by one
    for(size_t ii = values.size() - 1; ii > 0; ii--) {
        // Move current root to end
        std::swap(values[0], values[ii]);
        // again call max heapify on the reduced heap
        heapify(values, ii, 0);
    }
}

void timed_heap_sort(std::vector<int> &values) {
    const auto t1 = std::chrono::high_resolution_clock::now();
    heap_sort(values);
    finish_timing(t1);
}

void run_all_timed_sorts(All_Values &all_values) {
    using enum Sort_Type;
    using Type = std::underlying_type_t<Sort_Type>;
    timed_bubble_sort(all_values[static_cast<Type>(Bubble_Sort)]);
    timed_selection_sort(all_values[static_cast<Type>(Selection_Sort)]);
    timed_insertion_sort(all_values[static_cast<Type>(Insertion_Sort)]);
    timed_quick_sort(all_values[static_cast<Type>(Quick_Sort)], 0, all_values[static_cast<Type>(Quick_Sort)].size() - 1);
    timed_merge_sort(all_values[static_cast<Type>(Merge_Sort)], 0, all_values[static_cast<Type>(Merge_Sort)].size() - 1);
    timed_shell_sort(all_values[static_cast<Type>(Shell_Sort)]);
    timed_heap_sort(all_values[static_cast<Type>(Heap_Sort)]);
}

void run_insertion_sort_with_print(std::vector<int> &values) {
    timed_insertion_sort(values);
    print_array(values);
}
