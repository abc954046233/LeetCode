//
// Created by liyang on 2020/10/3.
//

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;

        auto word_beg = s.cbegin();     // 总是指向一个单词的第一个字符
        string::const_iterator word_it;     // 用来遍历一个单词

        while (true) {
            while (word_beg != s.cend() && *word_beg == ' ')
                word_beg++;
            if (word_beg == s.cend())
                break;

            string word;
            word_it = word_beg;
            while (word_it != s.cend() && *word_it != ' ') {
                word.push_back(*word_it);
                word_it++;
            }
            words.push_back(word);

            if (word_it == s.cend())
                break;

            word_beg = word_it;
        }

        string ret;
        for (auto it = words.crbegin(); it != words.crend(); ++it) {
            ret += *it + ' ';
        }
        if (!ret.empty())
            ret.pop_back();

        return ret;
    }
};

int main() {
    Solution().reverseWords("the sky is blue");
}