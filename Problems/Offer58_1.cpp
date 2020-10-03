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

        auto word_beg = s.cbegin();         // 指向一个单词的第一个字符
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

// 以上为常规解法
// 将14-35行的正序遍历改为逆序遍历
// word的每个字符放入栈中实现逆序
// 可以减少38-40行的遍历时间
//
// word的逆序若采用[word_beg..word_end]直接加入，可以省略word入栈出栈的时间