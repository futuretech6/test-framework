#include <solution.h>

void Solution::sort(std::vector<int> &array) {
    for (auto i = array.begin(); i != array.end(); i++) {
        for (auto j = i + 1; j != array.end(); j++) {
            if (*i > *j) {
                auto tmp = *i;
                *i       = *j;
                *j       = tmp;
            }
        }
    }
}
