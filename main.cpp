#include <string>

#include "array.hpp"
#include "sorting_algos.hpp"

int main() {
    int aa[SIZE_OF_ARRAY];
    memcpy(aa, array, SIZE_OF_ARRAY);
    timed_bubble_sort(aa, SIZE_OF_ARRAY);

    int bb[SIZE_OF_ARRAY];
    memcpy(bb, array, SIZE_OF_ARRAY);
    timed_selection_sort(bb, SIZE_OF_ARRAY);

    int cc[SIZE_OF_ARRAY];
    memcpy(cc, array, SIZE_OF_ARRAY);
    timed_insertion_sort(cc, SIZE_OF_ARRAY);

    int dd[SIZE_OF_ARRAY];
    memcpy(dd, array, SIZE_OF_ARRAY);
    timed_quick_sort(dd, 0, SIZE_OF_ARRAY - 1);

    int ee[SIZE_OF_ARRAY];
    memcpy(ee, array, SIZE_OF_ARRAY);
    timed_merge_sort(ee, SIZE_OF_ARRAY, 0, SIZE_OF_ARRAY - 1);

    int ff[SIZE_OF_ARRAY];
    memcpy(ff, array, SIZE_OF_ARRAY);
    timed_shell_sort(ff, SIZE_OF_ARRAY);

    int gg[SIZE_OF_ARRAY];
    memcpy(gg, array, SIZE_OF_ARRAY);
    timed_heap_sort(gg, SIZE_OF_ARRAY);

    return 0;
}