//
// Created by liyang on 2020/10/25.
//

#define is_odd(n) (n % 2 != 0)

double myPow(double x, int n){
    double ans = 0;

    if (n == 0) {
        ans = 1;
    }
    else if (n == 1) {
        ans = x;
    }
    else if (n > 0) {
        if (is_odd(n)) {
            ans = myPow(x, n / 2);
            ans = ans * ans * x;
        }
        else {
            ans = myPow(x, n / 2);
            ans = ans * ans;
        }
    } else {
        // 当 n == INT_MIN 时，myPow(x, -n) -n会溢出
        // 这里为了防止溢出
        ans = 1 / (myPow(x, -n - 1) * x);
    }

    return ans;
}