//
// Created by liyang on 2020/2/25.
//

#ifndef ARRAY_28_SOLUTION_H
#define ARRAY_28_SOLUTION_H

#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) return;
        int cur = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) continue;
            nums[cur++] = nums[i];
        }
        for (int i = cur; i < nums.size(); ++i) {
            nums[i] = 0;
        }
    }
};


#endif //ARRAY_28_SOLUTION_H
