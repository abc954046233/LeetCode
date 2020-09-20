#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

int main() {
    int k = 4;
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    Solution().rotate(nums, k);
    for (auto num : nums) cout << num << " ";
}
