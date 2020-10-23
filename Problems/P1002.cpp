//
// Created by liyang on 2020/10/14.
//
#include <string>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Solution {
public:
    static inline int index_of(char c) {
        return static_cast<int>(c) - 97;
    }

    static inline char char_of(int index) {
        return static_cast<char>(index + 97);
    }
    vector<string> commonChars(vector<string>& A) {
        int min_cnt[26];
        // get min_cnt
        for (auto s : A) {
            int cnt[26] = {0};
            // get cnt
            for (auto c : s) {
                ++cnt[index_of(c)];
            }

            for (int i = 0; i < 26; ++i) {
                if (cnt[i] < min_cnt[i])
                    min_cnt[i] = cnt[i];
            }
            memset(cnt, 0, 26);
        }

        vector<string> ret;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < min_cnt[i]; ++j) {
                string s;
                s.push_back(char_of(i));
                ret.push_back(s);
            }
        }

        return ret;
    }
};

int main() {
    vector<string> A = {"bella", "label", "roller"};
    for (auto c : Solution().commonChars(A)) {
        cout << c << endl;
    }
}