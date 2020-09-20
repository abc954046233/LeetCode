#include <iostream>
#include "Solution.h"

vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

int main() {
    int newSize = Solution::removeDuplicates(nums);
    for (int i = 0; i < newSize; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl << newSize << endl;
    return 0;
}
