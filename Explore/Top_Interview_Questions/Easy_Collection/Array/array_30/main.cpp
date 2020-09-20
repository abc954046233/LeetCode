#include <iostream>
#include <vector>
#include "Solution.h"
using namespace std;

int main() {
    vector<char> v1 = {'.','.','.','.','5','.','.','1','.'};
    vector<char> v2 = {'.','4','.','3','.','.','.','.','.'};
    vector<char> v3 = {'.','.','.','.','.','3','.','.','1'};
    vector<char> v4 = {'8','.','.','.','.','.','.','2','.'};
    vector<char> v5 = {'.','.','2','.','7','.','.','.','.'};
    vector<char> v6 = {'.','1','5','.','.','.','.','.','.'};
    vector<char> v7 = {'.','.','.','.','.','2','.','.','.'};
    vector<char> v8 = {'.','2','.','9','.','.','.','.','.'};
    vector<char> v9 = {'.','.','4','.','.','.','.','.','.'};
    vector<vector<char>> v;
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);
    v.push_back(v6);
    v.push_back(v7);
    v.push_back(v8);
    v.push_back(v9);
    cout << Solution().isValidSudoku(v);
}