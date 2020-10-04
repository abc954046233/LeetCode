//
// Created by liyang on 2020/10/4.
//


//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static inline int get_sum(int a, int b, int c) {
        return a + b + c;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;  // 进位
        auto sum = get_sum(l1->val, l2->val, c);
        auto res = new ListNode(sum % 10, nullptr);

        c = sum / 10;
        auto pre = res;
        l1 = l1->next;
        l2 = l2->next;

        while (l1 != nullptr && l2 != nullptr) {
            sum = get_sum(l1->val, l2->val, c);
            auto cur = new ListNode(sum % 10, nullptr);
            pre->next = cur;

            c = sum / 10;
            pre = cur;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l1 == nullptr && l2 == nullptr && c == 0)
            return res;

        if (l1 == nullptr) {
            while (l2 != nullptr) {
                sum = get_sum(0, l2->val, c);
                auto cur = new ListNode(sum % 10, nullptr);
                pre->next = cur;

                c = sum / 10;
                pre = cur;
                l2 = l2->next;
            }
        }
        else if (l2 == nullptr) {
            while (l1 != nullptr) {
                sum = get_sum(l1->val, 0, c);
                auto cur = new ListNode(sum % 10, nullptr);
                pre->next = cur;

                c = sum / 10;
                pre = cur;
                l1 = l1->next;
            }
        }

        if (c != 0) {
            auto cur = new ListNode(c, nullptr);
            pre->next = cur;
        }

        return res;
    }
};


// 官方解法和上述思想一致，但代码更加精简
//class Solution {
//public:
//    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//        ListNode *head = nullptr, *tail = nullptr;
//        int carry = 0;
//        while (l1 || l2) {
//            int n1 = l1 ? l1->val: 0;
//            int n2 = l2 ? l2->val: 0;
//            int sum = n1 + n2 + carry;
//            if (!head) {
//                head = tail = new ListNode(sum % 10);
//            } else {
//                tail->next = new ListNode(sum % 10);
//                tail = tail->next;
//            }
//            carry = sum / 10;
//            if (l1) {
//                l1 = l1->next;
//            }
//            if (l2) {
//                l2 = l2->next;
//            }
//        }
//        if (carry > 0) {
//            tail->next = new ListNode(carry);
//        }
//        return head;
//    }
//};
//
//作者：LeetCode-Solution
//        链接：https://leetcode-cn.com/problems/add-two-numbers/solution/liang-shu-xiang-jia-by-leetcode-solution/
//来源：力扣（LeetCode）
//著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。