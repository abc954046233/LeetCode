//
// Created by liyang on 2020/9/21.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty())
            return false;

        int rowNumber = matrix.size();
        int columnNumber = matrix[0].size();

        // 每次取可能范围的右上角
        int i = 0, j = columnNumber - 1;
        while(i < rowNumber && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            // 没找到则通过关系缩小范围
            else if (matrix[i][j] > target)
                j--;
            else i++;
        }

        return false;
    }
};

// 由于横向纵向递增，根据矩阵元素m[i][j]和target的关系可以确定target的可能存在范围
// 若m[i][j] > target则target可能出现在m[i][j]的左边和上边
// 即[0..i-1][0..columnNumber], [0..rowNumber][0..j-1]都是target可能存在的范围

// 通过取边角使得某边为空可以少考虑一种情况
// 如取右上角，且 m[i][j] > target，由于上边不存在，则只可能在左边
//               m[i][j] < target，由于右边不存在，则只可能在下边
// 该题解便基于这种思想