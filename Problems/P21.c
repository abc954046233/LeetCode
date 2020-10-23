//
// Created by liyang on 2020/10/23.
//
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

// 如果已知l1, l2的末尾，则可以通过加两个哨兵位简化代码
// 实际上是next指针重排的一个过程
// 原来两个链表中的结点的next指向了在合并后的链表中应该指向的元素
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    // l3为带头结点的链表
    Node *l3 = malloc(sizeof(Node));
    l3->next = NULL;

    Node *cur = l3;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            cur->next = l1;

            l1 = l1->next;
            cur = cur->next;
        }
        else {
            cur->next = l2;

            l2 = l2->next;
            cur = cur->next;
        }
    }

    if (l1 != NULL) {
        while (l1 != NULL) {
            cur->next = l1;

            l1 = l1->next;
            cur = cur->next;
        }
    }

    if (l2 != NULL) {
        while (l2 != NULL) {
            cur->next = l2;

            l2 = l2->next;
            cur = cur->next;
        }
    }

    return l3->next;
}