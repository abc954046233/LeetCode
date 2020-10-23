//
// Created by liyang on 2020/10/23.
//
#include <string.h>
#include <malloc.h>

#define true 1
#define false 0

// 返回字符串s长度为n的前缀
// 若n大于s的长度，则返回s本身
char *get_prefix(const char *s, int n) {
    int s_size = strlen(s);
    n = n > s_size ? s_size : n;

    char *prefix = malloc(sizeof(char) * (n + 1));

    for (int i = 0; i < n; ++i) {
        prefix[i] = s[i];
    }
    prefix[n] = '\0';

    return prefix;
}

char *longestCommonPrefix(char **strs, int strsSize) {
    char *prefix;

    if (strsSize == 0) {
        prefix = malloc(sizeof(char));
        prefix[0] = '\0';
        return prefix;
    }
    if (strsSize == 1) {
        prefix = malloc(sizeof(char) * (strlen(strs[0]) + 1));
        strcpy(prefix, strs[0]);
        return prefix;
    }

    int max_len = 0;
    for (int i = 0; i < strsSize; ++i) {
        int len = strlen(strs[i]);
        if (len > max_len)
            max_len = len;
    }

    int i = 0;
    int prefix_len = 1;
    prefix = get_prefix(strs[0], prefix_len);

    while (true) {
        if (i == strsSize) {
            i = 0;
            prefix_len++;

            if (prefix_len > max_len)
                return prefix;

            prefix = get_prefix(strs[0], prefix_len);
        }

        // 只需要比较新加的字符
        if (strcmp(prefix + prefix_len - 1, get_prefix(strs[i], prefix_len) + prefix_len - 1) == 0) {
            i++;
        } else {
            prefix[prefix_len - 1] = '\0';
            return prefix;
        }
    }
}