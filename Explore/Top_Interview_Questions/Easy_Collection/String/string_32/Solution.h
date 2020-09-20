//
// Created by liyang on 2020/2/26.
//

#ifndef STRING_32_SOLUTION_H
#define STRING_32_SOLUTION_H

#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        if (s.empty() || s.size() == 1) return;
        for (int i = 0; i <= s.size() / 2 - 1; ++i) {
            int symmetry = s.size() - 1 - i;
            // exchange
            int tmp = s[symmetry];
            s[symmetry] = s[i];
            s[i] = tmp;
        }
    }
};


#endif //STRING_32_SOLUTION_H
