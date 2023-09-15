#include <iostream>
#include <solution.h>
#include <vector>

int main(int argc, char *argv[]) {
    using namespace std;
    vector<int> array = {3, 4, 2, 1};
    Solution().sort(array);
    for (auto &i : array) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
