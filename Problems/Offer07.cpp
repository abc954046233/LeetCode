//
// Created by liyang on 2020/9/25.
//

#include <vector>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

using it = vector<int>::iterator;

class Solution {
public:
    // m的key为inorder中的元素值，value对应的下标
    // 可以快速获得inorder中值为v的元素的位置
    map<int, it> m;
    it pre_i;
    TreeNode* buildTree(it in_begin, it in_end) {
        if (in_begin == in_end)
            return nullptr;

        auto root = new TreeNode(*pre_i);
        pre_i++;
        root->left = buildTree(in_begin, m[root->val]);
        root->right = buildTree(m[root->val] + 1, in_end);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty())
            return nullptr;

        for (auto i = inorder.begin(); i != inorder.end(); ++i) {
            m[*i] = i;
        }

        pre_i = preorder.begin();

        return buildTree(inorder.begin(), inorder.end());
    }
};