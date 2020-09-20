//
// Created by liyang on 2020/2/25.
//

#ifndef ARRAY_26_SOLUTION_H
#define ARRAY_26_SOLUTION_H

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ret;

        if (nums1.empty() || nums2.empty()) return ret;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        for (int i : nums1) {
            auto it = lower_bound(nums2.cbegin(), nums2.cend(), i);
            // not found
            if (it == nums2.end() || *it != i)
                ;
            // found
            else {
                ret.push_back(*it);
                nums2.erase(it);
                if (nums2.empty()) break;
            }
        }
        return ret;
    }
};


#endif //ARRAY_26_SOLUTION_H
