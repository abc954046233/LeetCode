//
// Created by liyang on 2020/2/26.
//

#ifndef STRING_33_SOLUTION_H
#define STRING_33_SOLUTION_H

#include <cmath>
#include <climits>

class Solution {
public:
    int reverse(int x) {
        int reverse = 0;
        while (x) {
            int last = x % 10;
            // check if overflow
            if (reverse > INT_MAX / 10 || )
            reverse = reverse * 10 + last;
            x /= 10;
        }
    }
};


#endif //STRING_33_SOLUTION_H
