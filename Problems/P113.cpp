//
// Created by liyang on 2020/9/26.
//

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// 官方题解
class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;   // 保存到当前结点的路径

    void dfs(TreeNode* root, int sum) {
        if (root == nullptr)
            return;

        path.emplace_back(root->val);
        sum -= root->val;

        if (root->left == nullptr && root->right == nullptr && sum == 0) {
            ret.emplace_back(path);
        }

        dfs(root->left, sum);
        dfs(root->right, sum);


        path.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return ret;
    }
};

// 该题的解法是在前序遍历的基础上保存了到当前位置的路径
// 每到一个位置检查是否是一个符合要求的路径，是则加入
// 从该位置回到父亲时将path弹出一位
//
// emplace_back和push_back功能上相似
// 但emplace_back原地构造对象，不需要拷贝或者移动内存，效率更高

