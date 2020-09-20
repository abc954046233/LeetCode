//
// Created by liyang on 2020/2/25.
//

#ifndef ARRAY_29_SOLUTION_H
#define ARRAY_29_SOLUTION_H

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
private:
    pair<int, int> search(vector<pair<int, int>> v, int key) {
        int lo = 0;
        int hi = v.size() - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (key < v[mid].first) hi = mid - 1;
            else if (key > v[mid].first) lo = mid + 1;
            else return v[mid];
        }
        return pair<int, int>(-1, -1);
    }
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ret;
        if (nums.empty()) return ret;

        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); ++i) {
            pair<int, int> p(nums[i], i);
            v.push_back(p);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); ++i) {
            int find = target - v[i].first;
            pair<int, int> tmp = search(v, find);
            if (tmp.second != -1 && tmp.second != v[i].second) {
                ret.push_back(v[i].second);
                ret.push_back(tmp.second);
                break;
            }
        }
        return ret;
    }
};


#endif //ARRAY_29_SOLUTION_H
