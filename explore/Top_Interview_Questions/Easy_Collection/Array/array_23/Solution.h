//
// Created by liyang on 2020/2/23.
//

#ifndef ARRAY_23_SOLUTION_H
#define ARRAY_23_SOLUTION_H

#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (k == 0 || k == nums.size() ||
            nums.empty() || nums.size() == 1) return;
        else {
            int cnt = 0;
            k %= nums.size();
            for (int i = 0; cnt < nums.size(); ++i) {
                int cur_index = i, cur_num = nums[cur_index];
                int target;
                do {
                    target = (cur_index + k) % nums.size();
                    int tmp = nums[target];
                    nums[target] = cur_num;

                    cur_index = target;
                    cur_num = tmp;
                    cnt++;
                } while (target != i);
            }
        }
    }
};


#endif //ARRAY_23_SOLUTION_H
