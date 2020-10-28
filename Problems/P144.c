#include <stdlib.h>

#define MAX_NODE_NUM 5000
#define STACK_CAPACITY 5000

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }

    int* ret = malloc(sizeof(int) * MAX_NODE_NUM);
    int ret_size = 0;

    struct TreeNode* stack[STACK_CAPACITY];
    int top = 0;

    struct TreeNode* node = root;
    while (top != 0 || node != NULL) {
        while (node != NULL) {
            ret[ret_size++] = node->val;
            stack[top++] = node;
            node = node->left;
        }
        node = stack[--top];
        node = node->right;
    }

    *returnSize = ret_size;
    return ret;
}