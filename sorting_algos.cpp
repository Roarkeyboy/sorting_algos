#include "sorting_algos.hpp"

#include <chrono>
#include <iostream>

void print_array(int * array, int array_size) {
    for(int ii = 0; ii < array_size; ii++) {
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

void bubble_sort(int * array, int array_size) {
    std::cout << "Bubble sort: \t";
    int temp;
    for(int ii = 0; ii < array_size; ii++) {
        for(int jj = ii + 1; jj < array_size; jj++) {
            if(array[jj] < array[ii]) {
                temp = array[ii];
                array[ii] = array[jj];
                array[jj] = temp;
            }
        }
    }
}

void timed_bubble_sort(int * array, int array_size) {
    auto t1 = std::chrono::high_resolution_clock::now();
    bubble_sort(array, array_size);
    finish_timing(t1);
}

static int find_smallest(int * array, int array_size, int ii) {
    int ele_small = array[ii];
    int position = ii;
    for(int jj = ii + 1; jj < array_size; jj++) {
        if(array[jj] < ele_small) {
            ele_small = array[jj];
            position = jj;
        }
    }
    return position;
}

void selection_sort(int * array, int array_size) {
    std::cout << "Selection sort: ";
    int pos, temp;
    for(int ii = 0; ii < array_size; ii++) {
        pos = find_smallest(array, array_size, ii);
        temp = array[ii];
        array[ii] = array[pos];
        array[pos] = temp;
    }
}

void timed_selection_sort(int * array, int array_size) {
    auto t1 = std::chrono::high_resolution_clock::now();
    selection_sort(array, array_size);
    finish_timing(t1);
}

void insertion_sort(int * array, int array_size) {
    std::cout << "Insertion sort: ";
    for(int ii = 1; ii < array_size; ii++) {
        int temp = array[ii];
        int j = ii - 1;
        while(j >= 0 && temp <= array[j]) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
}

void timed_insertion_sort(int * array, int array_size) {
    auto t1 = std::chrono::high_resolution_clock::now();
    insertion_sort(array, array_size);
    finish_timing(t1);
}

static void swap(int * a, int * b) {
    const int t = *a;
    *a = *b;
    *b = t;
}

static int partition(int * array, int low, int high) {
    int pivot = array[low];
    int count = 0;
    for (int ii = low + 1; ii <= high; ii++) {
        if(array[ii] <= pivot) {
            count++;
        }
    }
    // Giving pivot element its correct position
    int pivot_index = low + count;
    swap(&array[pivot_index], &array[low]);
    // Sorting left and right parts of the pivot element
    int ii = low, jj = high;
    while(ii < pivot_index && jj > pivot_index) {
        while(array[ii] <= pivot) {
            ii++;
        }
        while(array[jj] > pivot) {
            jj--;
        }
        if(ii < pivot_index && jj > pivot_index) {
            swap(&array[ii++], &array[jj--]);
        }
    }
    return pivot_index;
}

void timed_quick_sort(int * array, int low, int high) {
    auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << "Quick sort: \t";
    quick_sort(array, low, high);
    finish_timing(t1);
}

void quick_sort(int * array, int low, int high) {
    if(low < high) {
        const int pivot = partition(array, low, high);
        quick_sort(array, low, pivot - 1);
        quick_sort(array, pivot + 1, high);
    }
}

static void merge(int * array, int array_size, int low, int high, int mid) {
    int cc[array_size];
    int ii = low;
    int kk = low;
    int jj = mid + 1;
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

void timed_merge_sort(int * array, int array_size, int low, int high) {
    auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << "Merge sort: \t";
    merge_sort(array, array_size, low, high);
    finish_timing(t1);
}

void merge_sort(int * array, int array_size, int low, int high) {
    if(low < high){
        //divide the array at mid and sort independently using merge sort
        const int mid = (low + high) / 2;
        merge_sort(array, array_size, low, mid);
        merge_sort(array, array_size, mid + 1, high);
        //merge or conquer sorted arrays
        merge(array, array_size, low, high, mid);
    }
}

void timed_shell_sort(int * array, int array_size) {
    auto t1 = std::chrono::high_resolution_clock::now();
    shell_sort(array, array_size);
    finish_timing(t1);
}

void shell_sort(int * array, int array_size) {
    std::cout << "Shell sort: \t";
    for(int gap = array_size / 2; gap > 0; gap /= 2) {
        for(int ii = gap; ii < array_size; ii++) {
            //sort sub lists created by applying gap
            int temp = array[ii];
            int jj;
            for(jj = ii; jj >= gap && array[jj - gap] > temp; jj -= gap) {
                array[jj] = array[jj - gap];
            }
            array[jj] = temp;
        }
    }
}


// function to heapify the tree
static void heapify(int * array, int array_size, int root) {
    int largest = root; // root is the largest element
    const int ll = 2 * root + 1;
    const int rr = 2 * root + 2;
    // If left child is larger than root
    if(ll < array_size && array[ll] > array[largest]) {
        largest = ll;
    }
    // If right child is larger than largest so far
    if(rr < array_size && array[rr] > array[largest]) {
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

void timed_heap_sort(int * array, int array_size) {
    auto t1 = std::chrono::high_resolution_clock::now();
    heap_sort(array, array_size);
    finish_timing(t1);
}

void heap_sort(int * array, int array_size) {
    std::cout << "Heap sort: \t";
    // build heap
    for(int ii = array_size / 2 - 1; ii >= 0; ii--) {
        heapify(array, array_size, ii);
    }
    // extracting elements from heap one by one
    for(int ii = array_size - 1; ii >= 0; ii--) {
        // Move current root to end
        swap(&array[0], &array[ii]);
        // again call max heapify on the reduced heap
        heapify(array, ii, 0);
    }
}