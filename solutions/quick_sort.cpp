#include "solution.h"

std::vector<int> *helper_pointer;

template <typename T>
typename std::vector<T>::iterator quick_partition(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end) {
    auto const pivot_val = *(end - 1);

    auto i = begin;  // i-begin: num of values < pivot_val

    for (auto j = begin; j < end - 1; j++) {
        if (*j < pivot_val) {
            std::swap(*i, *j);
            i++;
        }
    }

    std::swap(*i, *(end - 1));
    return i;
}

template <typename T>
void quick_sort(typename std::vector<T>::iterator begin, typename std::vector<T>::iterator end) {
    if (begin < end) {
        auto pivot = quick_partition<T>(begin, end);
        quick_sort<T>(begin, pivot);    // [begin, pivot-1]
        quick_sort<T>(pivot + 1, end);  // [pivot+1, end-1]
    }
}

void Solution::sort(std::vector<int> &array) {
    helper_pointer = &array;
    quick_sort<int>(array.begin(), array.end());
}
