//
// Created by liyang on 2020/10/5.
//

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr)
            return nullptr;

        root->left = invertTree(root->left);
        root->right = invertTree(root->right);

        TreeNode* tmp;
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;

        return root;
    }
};

int main() {
    vector<TreeNode> n(7);

    n[0] = TreeNode(4);

    n[1] = TreeNode(2);
    n[2] = TreeNode(7);

    n[3] = TreeNode(1);
    n[4] = TreeNode(3);
    n[5] = TreeNode(6);
    n[6] = TreeNode(9);

    n[0].left = &n[1];
    n[0].right = &n[2];

    n[1].left = &n[3];
    n[1].right = &n[4];

    n[2].left = &n[5];
    n[2].right = &n[6];

    Solution().invertTree(&n[0]);

    cout << "hello, world";
}