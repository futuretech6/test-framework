#include <algorithm>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

#include <solution.h>

int main(int argc, char *argv[]) {
    using namespace std;

    string path = "tests/";
    for (const auto &entry : filesystem::directory_iterator(path)) {
        if (!(entry.path().string().find("input") != string::npos)) {
            continue;
        }

        cout << "\e[33mTesting " << entry.path() << "\t......";

        vector<int> array;
        {
            ifstream in(entry.path());
            int val;
            while (in >> val) {
                array.push_back(val);
            }
            in.close();
        }

        vector<int> sorted = array;
        sort(sorted.begin(), sorted.end());

        Solution().sort(array);

        if (array != sorted) {
            cout << "\e[31mFailed\e[0m" << endl;
            cout << "Expected: ";
            printVec(sorted);
            cout << "Got:      ";
            printVec(array);
            continue;
        }
        cout << "\e[32mPassed\e[0m" << endl;
    }

    return 0;
}
