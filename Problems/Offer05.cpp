//
// Created by liyang on 2020/9/25.
//

#include <string>
using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for (auto c : s) {
            if (c == ' ') {
                res.push_back('%');
                res.push_back('2');
                res.push_back('0');
            }
            else
                res.push_back(c);
        }
        return res;
    }
};

// 书上的是原址生成结果
// 从后往前生成避免了移动元素