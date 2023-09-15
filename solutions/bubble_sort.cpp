#include <solution.h>

template <typename T>
void swap(T &a, T &b) {
    T tmp = a;
    a     = b;
    b     = tmp;
}

void Solution::sort(std::vector<int> &array) {
    for (auto i = array.begin(); i != array.end(); i++) {
        for (auto j = i + 1; j != array.end(); j++) {
            if (*i > *j) {
                swap(*i, *j);
            }
        }
    }
}
