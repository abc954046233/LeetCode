//
// Created by liyang on 2020/9/25.
//

#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (head == nullptr)
            return nullptr;

        stack<ListNode*> s;
        ListNode *cur = head;
        while (cur != nullptr) {
            s.push(cur);
            cur = cur->next;
        }
        for (int i = 1; i < k; ++i) {
            s.pop();
        }
        return s.top();
    }
};