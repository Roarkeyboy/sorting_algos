#include "sorting_algos.hpp"

#include <chrono>
#include <iostream>

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")

void print_array(std::vector<int> & array) {
    for(size_t ii = 0; ii < array.size(); ii++) {
        std::cout << array[ii] << "\t";
    }
    std::cout << std::endl;
}

static void finish_timing(auto t1) {
    auto t2 = std::chrono::high_resolution_clock::now();
    /* Getting number of milliseconds as an integer. */
    auto ms_int = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    /* Getting number of milliseconds as a double. */
    std::chrono::duration<double, std::milli> ms_double = t2 - t1;
    std::cout << ms_double.count() << " ms" << std::endl;
}

void bubble_sort(std::vector<int> & array) {
    std::cout << "Bubble sort: \t";
    int temp;
    for(size_t ii = 0; ii < array.size(); ii++) {
        for(size_t jj = ii + 1; jj < array.size(); jj++) {
            if(array[jj] < array[ii]) {
                temp = array[ii];
                array[ii] = array[jj];
                array[jj] = temp;
            }
        }
    }
}

void timed_bubble_sort(std::vector<int> & array) {
    auto t1 = std::chrono::high_resolution_clock::now();
    bubble_sort(array);
    finish_timing(t1);
}

static size_t find_smallest(std::vector<int> & array, const size_t ii) {
    int ele_small = array[ii];
    size_t position = ii;
    for(size_t jj = ii + 1; jj < array.size(); jj++) {
        if(array[jj] < ele_small) {
            ele_small = array[jj];
            position = jj;
        }
    }
    return position;
}

void selection_sort(std::vector<int> & array) {
    std::cout << "Selection sort: ";
    int temp;
    size_t pos;
    for(size_t ii = 0; ii < array.size(); ii++) {
        pos = find_smallest(array, ii);
        temp = array[ii];
        array[ii] = array[pos];
        array[pos] = temp;
    }
}

void timed_selection_sort(std::vector<int> & array) {
    auto t1 = std::chrono::high_resolution_clock::now();
    selection_sort(array);
    finish_timing(t1);
}

void insertion_sort(std::vector<int> & array) {
    std::cout << "Insertion sort: ";
    for(size_t ii = 1; ii < array.size(); ii++) {
        size_t temp = static_cast<size_t>(array[ii]);
        size_t jj = ii - 1;
        while(jj > 0 && temp <= static_cast<size_t>(array[jj])) {
            array[jj + 1] = array[jj];
            jj--;
        }
        array[jj + 1] = temp;
    }
}

void timed_insertion_sort(std::vector<int> & array) {
    auto t1 = std::chrono::high_resolution_clock::now();
    insertion_sort(array);
    finish_timing(t1);
}

static void swap(int * a, int * b) {
    const int t = *a;
    *a = *b;
    *b = t;
}

static size_t partition(std::vector<int> & array, const size_t low, const size_t high) {
    const size_t pivot = static_cast<size_t>(array[low]);
    size_t count = 0;
    for (size_t ii = low + 1; ii <= high; ii++) {
        if(static_cast<size_t>(array[ii]) <= pivot) {
            count++;
        }
    }
    // Giving pivot element its correct position
    const size_t pivot_index = low + count;
    swap(&array[pivot_index], &array[low]);
    // Sorting left and right parts of the pivot element
    size_t ii = low, jj = high;
    while(ii < pivot_index && jj > pivot_index) {
        while(static_cast<size_t>(array[ii]) <= pivot) {
            ii++;
        }
        while(static_cast<size_t>(array[jj]) > pivot) {
            jj--;
        }
        if(ii < pivot_index && jj > pivot_index) {
            swap(&array[ii++], &array[jj--]);
        }
    }
    return pivot_index;
}

void quick_sort(std::vector<int> & array, const size_t low, const size_t high) {
    if(low < high) {
        const size_t pivot = partition(array, low, high);
        quick_sort(array, low, pivot - 1);
        quick_sort(array, pivot + 1, high);
    }
}

void timed_quick_sort(std::vector<int> & array, const size_t low, const size_t high) {
    auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << "Quick sort: \t";
    quick_sort(array, low, high);
    finish_timing(t1);
}

static void merge(std::vector<int> & array, const size_t low, const size_t high, const size_t mid) {
    std::vector<int> cc;
    cc.reserve(array.size());
    size_t ii = low;
    size_t kk = low;
    size_t jj = mid + 1;
    while(ii <= mid && jj <= high) {
        if(array[ii] < array[jj]) {
            cc[kk] = array[ii];
            kk++;
            ii++;
        }
        else {
            cc[kk] = array[jj];
            kk++;
            jj++;
        }
    }
    while(ii <= mid) {
        cc[kk] = array[ii];
        kk++;
        ii++;
    }
    while(jj <= high) {
        cc[kk] = array[jj];
        kk++;
        jj++;
    }
    for(ii = low; ii < kk; ii++) {
        array[ii] = cc[ii];
    }
}

void merge_sort(std::vector<int> & array, const size_t low, const size_t high) {
    if(low < high){
        //divide the array at mid and sort independently using merge sort
        const size_t mid = (low + high) / 2;
        merge_sort(array, low, mid);
        merge_sort(array, mid + 1, high);
        //merge or conquer sorted arrays
        merge(array, low, high, mid);
    }
}

void timed_merge_sort(std::vector<int> & array, const size_t low, const size_t high) {
    auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << "Merge sort: \t";
    merge_sort(array, low, high);
    finish_timing(t1);
}

void shell_sort(std::vector<int> & array) {
    std::cout << "Shell sort: \t";
    for(size_t gap = array.size() / 2; gap > 0; gap /= 2) {
        for(size_t ii = gap; ii < array.size(); ii++) {
            //sort sub lists created by applying gap
            const size_t temp = static_cast<size_t>(array[ii]);
            size_t jj;
            for(jj = ii; jj >= gap && static_cast<size_t>(array[jj - gap]) > temp; jj -= gap) {
                array[jj] = array[jj - gap];
            }
            array[jj] = temp;
        }
    }
}

void timed_shell_sort(std::vector<int> & array) {
    auto t1 = std::chrono::high_resolution_clock::now();
    shell_sort(array);
    finish_timing(t1);
}

// function to heapify the tree
static void heapify(std::vector<int> & array, const size_t array_size, const size_t root) {
    size_t largest = root; // root is the largest element
    const size_t ll = 2 * root + 1;
    const size_t rr = 2 * root + 2;
    // If left child is larger than root
    if(ll < array.size() && array[ll] > array[largest]) {
        largest = ll;
    }
    // If right child is larger than largest so far
    if(rr < array.size() && array[rr] > array[largest]) {
        largest = rr;
    }
    // If largest is not root
    if(largest != root) {
        //swap root and largest
        swap(&array[root], &array[largest]);
        // Recursively heapify the sub-tree
        heapify(array, array_size, largest);
    }
}

void heap_sort(std::vector<int> & array) {
    std::cout << "Heap sort: \t";
    // build heap
    for(size_t ii = array.size() / 2 - 1; ii > 0; ii--) {
        heapify(array, array.size(), ii);
    }
    // extracting elements from heap one by one
    for(size_t ii = array.size() - 1; ii > 0; ii--) {
        // Move current root to end
        swap(&array[0], &array[ii]);
        // again call max heapify on the reduced heap
        heapify(array, ii, 0);
    }
}

void timed_heap_sort(std::vector<int> & array) {
    auto t1 = std::chrono::high_resolution_clock::now();
    heap_sort(array);
    finish_timing(t1);
}

void run_all_timed_sorts(std::vector<std::vector<int>> & arrays) {
    timed_bubble_sort(arrays[static_cast<size_t>(Sort_Type::Bubble_Sort)]);
    timed_selection_sort(arrays[static_cast<size_t>(Sort_Type::Selection_Sort)]);
    timed_insertion_sort(arrays[static_cast<size_t>(Sort_Type::Insertion_Sort)]);
    timed_quick_sort(arrays[static_cast<size_t>(Sort_Type::Quick_Sort)], 0, arrays[static_cast<size_t>(Sort_Type::Quick_Sort)].size() - 1);
    timed_merge_sort(arrays[static_cast<size_t>(Sort_Type::Merge_Sort)], 0, arrays[static_cast<size_t>(Sort_Type::Merge_Sort)].size() - 1);
    timed_shell_sort(arrays[static_cast<size_t>(Sort_Type::Shell_Sort)]);
    timed_heap_sort(arrays[static_cast<size_t>(Sort_Type::Heap_Sort)]);
}
