#include <stdio.h>
#include <string.h>
#include <limits.h>

/**
 * 最开始我的dp初始化调用为：
 * memset(dp, -1, sizeof(dp));
 * 旨在把dp的每一项都变为unsigned所能表示的最大值
 * return语句为：return dp[T] == UINT_MAX ? -1 : dp[T];
 *
 * 逻辑上讲是没有错的，但是把dp的每一项设到最大值会存在溢出的情况导致结果不正确
 * 溢出情况在于：dp[clips[j][0]]无法剪辑，则dp[clips[j][0]] + 1应该是一个很大的值
 * 这里却会变成0，导致dp[i]的更新错误
 *
 */

#define min(a, b) (a > b ? b : a)

int videoStitching(int** clips, int clipsSize, int* clipsColSize, int T) {
    // dp[i]表示[0, i)所需片段的最小数目
    unsigned dp[T + 1];
    memset(dp, 0x7f, sizeof(dp));
    dp[0] = 0;

    for (int i = 1; i <= T; ++i) {
        for (int j = 0; j < clipsSize; ++j) {
            if (i >= clips[j][0] && i <= clips[j][1]) {
                dp[i] = min(dp[clips[j][0]] + 1, dp[i]);
            }
        }
    }

    return dp[T] == 0x7f7f7f7f ? -1 : dp[T];
}
