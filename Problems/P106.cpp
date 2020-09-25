//
// Created by liyang on 2020/9/25.
//

#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;

      explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

using it = vector<int>::iterator;

class Solution {
public:
    TreeNode* buildTree(it i_begin, it i_end, it p_begin, it p_end) {
        if (p_end - 1 < p_begin)
            return nullptr;

        auto* root = new TreeNode(*(p_end - 1));
        auto root_it = find(i_begin, i_end, root->val);
        auto first_right_tree_node_in_post = p_begin + (root_it - i_begin);
        root->left = buildTree(i_begin, root_it, p_begin, first_right_tree_node_in_post);
        root->right = buildTree(root_it + 1, i_end,
                first_right_tree_node_in_post, p_end - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty()) {
            return nullptr;
        }

        return buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
};


// 自己写的代码效率并不高
// 根据官方题解，可做如下优化：
// 1. 建立一个哈希表，存放从val到index的键值对，从而提高查找效率
// 2. 如果每次都先建立右子树，则递归函数中不需要知道当前子树postorder中的范围
// 因为右子树的根结点总是postorder的当前范围中最后一个


