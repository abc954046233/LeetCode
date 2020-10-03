//
// Created by liyang on 2020/10/3.
//

#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ret;

        string::const_iterator word_beg;
        string::const_iterator word_end = s.cend() - 1;

        while (true) {
            while (word_end >= s.cbegin() && *word_end == ' ')
                word_end--;
            if (word_end < s.cbegin())
                break;

            word_beg = word_end;
            while (word_beg >= s.cbegin() && *word_beg != ' ')
                word_beg--;

            for (auto it = word_beg + 1; it <= word_end; ++it) {
                ret.push_back(*it);
            }
            ret.push_back(' ');

            if (word_beg < s.cbegin())
                break;

            word_end = word_beg;
        }

        if (!ret.empty())
            ret.pop_back();

        return ret;
    }
};

int main() {
    Solution().reverseWords(" ");
}

// Offer58-I的更优解
// 相比于常规解，少了存放单词的空间开销以及逆序输出单词的额外一次遍历