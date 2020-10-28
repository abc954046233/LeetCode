//
// Created by liyang on 2020/10/27.
//
#include <vector>
using namespace std;

class Solution {
public:
    const int MAX_NUM = 100;

    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // count[i]记录数字i在nums中出现的次数
        vector<int> count(MAX_NUM + 1);
        for (auto n : nums) {
            ++count[n];
        }

        // 现在count[i]表示nums中小于等于数字i的元素的个数
        for (int i = 1; i < count.size(); ++i) {
            count[i] += count[i - 1];
        }

        vector<int> answer;
        for (auto n : nums) {
            answer.push_back(n ? n : 0);
        }
        return answer;
    }
};

int main() {
    vector<int> nums = {5, 0, 10, 0, 10, 6};
    Solution().smallerNumbersThanCurrent(nums);
}