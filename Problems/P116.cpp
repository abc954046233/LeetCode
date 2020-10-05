//
// Created by liyang on 2020/10/5.
//

#include <cstdlib>

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;

        // 左子树不空则右子树必不空
        if (root->left != nullptr) {
            root->left->next = root->right;
            root->right->next =
                    (root->next == nullptr) ? nullptr : root->next->left;
        }

        connect(root->left);
        connect(root->right);

        return root;
    }
};

//基本思想：
//从根结点开始：
//    每个结点的左结点连接到右节点；
//    每个结点的右结点连接：
//        如果父节点的next为空，则连接NULL
//        如果父节点的next不为空，则连接next的左节点

//但是并没有直接的手段访问一个结点的父节点
//所以连接工作在知道结点的父节点的时候就完成
//也就是说在访问root时完成root->left和root->right的连接工作
//此时root的连接工作或者由其父节点完成，或者不需要完成（此时root为整个树的根节点，默认为NULL）