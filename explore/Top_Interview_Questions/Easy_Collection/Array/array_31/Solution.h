//
// Created by liyang on 2020/2/26.
//

#ifndef ARRAY_31_SOLUTION_H
#define ARRAY_31_SOLUTION_H

#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix.size() == 1) return;
        int n = matrix.size();
        // reverse every column
        for (int c = 0; c < n; ++c) {
            for (int r = 0; r <= n / 2 - 1; ++r) {
                int symmetry = n - 1 - r;
                // exchange
                int tmp = matrix[symmetry][c];
                matrix[symmetry][c] = matrix[r][c];
                matrix[r][c] = tmp;
            }
        }

        // exchange around the axis of symmetry
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < r; ++c) {
                int symmetry_r = c, symmetry_c = r;
                // exchange
                int tmp = matrix[symmetry_r][symmetry_c];
                matrix[symmetry_r][symmetry_c] = matrix[r][c];
                matrix[r][c] = tmp;
            }
        }
    }
};



#endif //ARRAY_31_SOLUTION_H
