//
// Created by liyang on 2020/2/25.
//

#ifndef ARRAY_27_SOLUTION_H
#define ARRAY_27_SOLUTION_H

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int p = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (p == 1) {
                digits[i]++;
                if (digits[i] == 10)
                    digits[i] = 0;
                else p = 0;
            }
        }
        if (p == 1) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};


#endif //ARRAY_27_SOLUTION_H
