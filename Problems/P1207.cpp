//
// Created by liyang on 2020/10/28.
//

#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        // 统计出现次数
        map<int, int> count;
        for (auto num : arr) {
            ++count[num];
        }

        set<int> occurred_time;
        for (auto c : count) {
            if (occurred_time.find(c.second) == occurred_time.end())
                occurred_time.insert(c.second);
            else
                return false;
        }

        return true;
    }
};