//
// Created by liyang on 2020/10/23.
//
#include <stdlib.h>
#include <stdio.h>

typedef int bool;
#define true 1
#define false 0

struct ListNode {
    int val;
    struct ListNode *next;
};

typedef struct ListNode Node;

// 反转链表
// 返回反转后链表的头结点
Node* reverse(Node *head) {
    // 链表只有一个元素
    if (head->next == NULL) {
        return head;
    }

    Node *cur = head, *next = head->next;
    head->next = NULL;  // head变为tail，置next为NULL
    while (next != NULL) {
        Node *tmp = next->next;

        next->next = cur;

        cur = next;
        next = tmp;
    }

    return cur;
}

// 返回链表中间节点
// 结点数为奇数返回中间结点
// 结点数为偶数返回前一半的最后一个结点
Node* get_mid_node(Node *head) {
    Node *slow_ptr = head, *fast_ptr = head;

    while (true) {
        fast_ptr = fast_ptr->next->next;
        if (fast_ptr == NULL || fast_ptr->next == NULL) break;
        slow_ptr = slow_ptr->next;
    }

    return slow_ptr;
}

bool isPalindrome(struct ListNode* head){
    // 空串和单字符串
    if (head == NULL || head->next == NULL) {
        return true;
    }

    Node *mid = get_mid_node(head);
    Node *tail = reverse(mid->next);

    Node *i = head, *j = tail;
    while (i != mid) {
        if (i->val != j->val)
            return false;
        i = i->next;
        j = j->next;
    }

    // 此时i指向mid
    // 若链表结点个数为偶数，则j指向后半部分的第一个结点，还需再比较一次
    // 若链表结点个数为奇数，则j == NULL，前一半和后一半都以比较完全，无需再比较
    if (j != NULL) {
        if (i->val != j->val) return false;
    }

    return true;
}

int main() {
    int n, v;

    Node *head;
    Node *tail;

    // n >= 1
    scanf("%d", &n);

    scanf("%d", &v);
    head = malloc(sizeof(Node));
    head->val = v;
    head->next = NULL;
    tail = head;

    for (int i = 1; i < n; ++i) {
        scanf("%d", &v);
        Node *n = malloc(sizeof(Node));
        n->val = v;
        n->next = NULL;

        tail->next = n;
        tail = n;
    }

    printf("%d\n", isPalindrome(head));
}