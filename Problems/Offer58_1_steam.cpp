//
// Created by liyang on 2020/10/3.
//

#include <sstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;

        stringstream S(s);

        string word;
        while (S >> word) {
            words.push_back(word);
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

// 利用C++中读入时忽略前后空白符的特性直接分割