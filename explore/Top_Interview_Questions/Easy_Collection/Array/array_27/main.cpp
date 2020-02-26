#include <iostream>
#include "Solution.h"
using namespace std;

int main() {
    vector<int> digits = {0};
    Solution().plusOne(digits);
    for (auto i : digits) {
        cout << i << " ";
    }
}
