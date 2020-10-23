#include <stdio.h>

// dp[i] has the value of fib(i)
int dp[31];

int fib(int N) {
    if (N == 0) return 0;
    if (N == 1) return 1;

    if (dp[N] == 0) { 
        int a = fib(N - 2);
        int b = fib(N - 1);
        dp[N] = a + b;
    }

    return dp[N]; 
}

int main() {
    printf("%d", fib(8));
    return 0;
}
