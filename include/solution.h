#include <vector>

class Solution {
  public:
    void sort(std::vector<int> &array);
};

#include <iostream>
#include <ostream>

inline void printVec(std::vector<int> &array, std::ostream &os = std::cout) {
    using namespace std;
    if (!array.empty()) {
        os << array.front();
        for (auto i = array.begin() + 1; i != array.end(); i++) {
            os << " " << *i;
        }
    }
    os << endl;
}
