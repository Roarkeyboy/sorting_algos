#ifndef SORTING_ALGOS_HPP
#define SORTING_ALGOS_HPP

void print_array(int * array, int array_size);
void bubble_sort(int * array, int array_size);
void timed_bubble_sort(int * array, int array_size);
void selection_sort(int * array, int array_size);
void timed_selection_sort(int * array, int array_size);
void insertion_sort(int * array, int array_size);
void timed_insertion_sort(int * array, int array_size);
void quick_sort(int * arr, int low, int high);
void timed_quick_sort(int * arr, int low, int high);
void merge_sort(int * array, int array_size, int low, int high);
void timed_merge_sort(int * array, int array_size, int low, int high);
void shell_sort(int * array, int array_size);
void timed_shell_sort(int * array, int array_size);
void heap_sort(int * array, int array_size);
void timed_heap_sort(int * array, int array_size);

#endif //SORTING_ALGOS_HPP