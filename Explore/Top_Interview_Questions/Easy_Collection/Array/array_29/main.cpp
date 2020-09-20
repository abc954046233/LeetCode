#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

int main() {
    vector<int> nums = {3, 2, 4};
    int target = 6;
    vector<int> v = Solution().twoSum(nums, target);
    for (int i : v) {
        cout << i << " ";
    }
}
