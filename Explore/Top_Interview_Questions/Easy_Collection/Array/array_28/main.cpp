#include <iostream>
#include "Solution.h"
using namespace std;

int main() {
    vector<int> nums = {0,1,0,3,12};
    Solution().moveZeroes(nums);
    for (int i : nums) {
        cout << i << " ";
    }
}
