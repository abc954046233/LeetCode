//
// Created by liyang on 2020/2/26.
//

#ifndef ARRAY_30_SOLUTION_H
#define ARRAY_30_SOLUTION_H

#include <vector>
using namespace std;

class Solution {
public:
    // flag[i] == true if number i has appeared.
    vector<bool> flag;
    void initialize_flag() {
        for (int i = 1; i <= 9; ++i) {
            flag[i] = false;
        }
    }
    int getDigit(char c) {
        return c - '0';
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool ret = true;

        flag.resize(10);

        // each row
        for (int i = 0; i < 9; ++i) {
            // each column
            initialize_flag();
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;
                int n = getDigit(board[i][j]);
                if (flag[n] == false) flag[n] = true;
                else {
                    ret = false;
                    break;
                }
            }
        }

        // each column
        for (int j = 0; j < 9; ++j) {
            // each row
            initialize_flag();
            for (int i = 0; i < 9; ++i) {
                char c = board[i][j];
                if (c == '.') continue;
                int n = getDigit(board[i][j]);
                if (flag[n] == false) flag[n] = true;
                else {
                    ret = false;
                    break;
                }
            }
        }

        // each 3 × 3 block
        int cnt = 0;
        int si = 0, sj = 0;
        while (cnt < 9) {
            cnt++;
            initialize_flag();
            for (int i = si; i < si + 3; ++i) {
                for (int j = sj; j < sj + 3; ++j) {
                    char c = board[i][j];
                    if (c == '.') continue;
                    int n = getDigit(board[i][j]);
                    if (flag[n] == false) flag[n] = true;
                    else {
                        ret = false;
                        break;
                    }
                }
            }
            sj = (sj + 3) % 9;
            if (cnt % 3 == 0) {
                si = (si + 3) % 9;
            }
        }
        return ret;
    }
};


#endif //ARRAY_30_SOLUTION_H
