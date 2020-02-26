//
// Created by liyang on 2020/2/24.
//

#ifndef ARRAY_24_SOLUTION_H
#define ARRAY_24_SOLUTION_H

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.empty()) return false;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) return true;
        }
        return false;
    }
};


#endif //ARRAY_24_SOLUTION_H
