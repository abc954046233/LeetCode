//
// Created by liyang on 2020/2/23.
//

#ifndef ARRAY_21_SOLUTION_H
#define ARRAY_21_SOLUTION_H

#include <vector>
using namespace std;

class Solution {
public:
    static int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;
        else {
            int currentNoRepeatNumber = 0;
            int cnt = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (i == 0) {
                    currentNoRepeatNumber = nums[i];
                    nums[cnt] = nums[i];
                    cnt++;
                } else {
                    if (nums[i] == currentNoRepeatNumber) continue;
                    else {
                        currentNoRepeatNumber = nums[i];
                        nums[cnt] = nums[i];
                        cnt++;
                    }
                }
            }
            return cnt;
        }
    }
};


#endif //ARRAY_21_SOLUTION_H
