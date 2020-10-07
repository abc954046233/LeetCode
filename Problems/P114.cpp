//
// Created by liyang on 2020/10/7.
//


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 简单的递归写法
class Solution {
public:
    // 把以root为根的二叉树转换为单链表
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;

        flatten(root->left);
        flatten(root->right);

        // 把右子链表接到左子链表后放到右子链表
        TreeNode* tmp;
        tmp = root->right;
        root->right = root->left;
        root->left = nullptr;

        if (root->right == nullptr) {
            root->right = tmp;
        } else {
            auto last = root->right;
            while (last->right != nullptr) {
                last = last->right;
            }
            last->right = tmp;
        }
    }
};

//// 官方题解，空间复杂度O(1)
//class Solution {
//public:
//    void flatten(TreeNode* root) {
//        TreeNode *curr = root;
//        while (curr != nullptr) {
//            if (curr->left != nullptr) {
//                auto next = curr->left;
//                auto predecessor = next;
//                while (predecessor->right != nullptr) {
//                    predecessor = predecessor->right;
//                }
//                predecessor->right = curr->right;
//                curr->left = nullptr;
//                curr->right = next;
//            }
//            curr = curr->right;
//        }
//    }
//};
//// 链表的顺序即为二叉树的前序遍历顺序
//// 在左子树找到前序遍历的最后一个结点，并使右子树接到其后
//// 再将左子树换到右子树上，左子树为空
