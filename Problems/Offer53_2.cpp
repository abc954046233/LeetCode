//
// Created by liyang on 2020/9/26.
//

#include <vector>
#include <iostream>
using namespace std;

int find(vector<int> &nums, int left, int right) {
    if (left > right) return left;
    int mid = (left + right) / 2;
    if (nums[mid] == mid) {
        find(nums, mid + 1, right);
    } else {
        find(nums, left, mid - 1);
    }
}

int missingNumber(vector<int>& nums) {
    return find(nums, 0, nums.size() - 1);
}