#include <algorithm>

#include "solution.h"

void Solution::sort(std::vector<int> &array) {
    std::sort(array.begin(), array.end(), [](auto &a, auto &b) { return a < b; });
}
