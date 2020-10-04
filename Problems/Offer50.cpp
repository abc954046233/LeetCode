//
// Created by liyang on 2020/10/4.
//

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    char firstUniqChar(string s) {
        unordered_map<char, int> char_cnt;
        for (const auto c : s) {
            ++char_cnt[c];
        }
        for (const auto c : s) {
            if (char_cnt[c] == 1)
                return c;
        }
        return ' ';
    }
};

int main() {
    Solution().firstUniqChar("leetcode");
}