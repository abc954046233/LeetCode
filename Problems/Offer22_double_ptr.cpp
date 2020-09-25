//
// Created by liyang on 2020/9/25.
//

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

        ListNode *latter = head, *former = head;
        for (int i = 1; i <= k; ++i) {
            former = former->next;
        }
        while (former != nullptr) {
            latter = latter->next;
            former = former->next;
        }
        return latter;
    }
};
