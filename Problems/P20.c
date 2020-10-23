//
// Created by liyang on 2020/10/23.
//
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

#define is_empty (top == 0)
#define push(i) brackets[top++] = i
#define pop top--
#define get_top brackets[top - 1]

bool isValid(char * s){
    char brackets[1000];    // 一个简易的栈，我们假设它足够大，所以不会满
    int top = 0;            // top指向栈顶的下一元素

    for (int i = 0; i < strlen(s); ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push(s[i]);
            continue;
        }

        if (is_empty)
            return false;

        if (s[i] == ')') {
            if (get_top != '(') {
                return false;
            }
            pop;
        }
        if (s[i] == ']') {
            if (get_top != '[') {
                return false;
            }
            pop;
        }
        if (s[i] == '}') {
            if (get_top != '{') {
                return false;
            }
            pop;
        }
    }

    if (!is_empty)
        return false;

    return true;
}

int main() {
    printf("%d", isValid("{[]}"));
}