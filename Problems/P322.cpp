class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i]：凑够i元需要的最小硬币数
        vector<int> dp(amount + 1, INT_MAX);

        // 凑够0元不需要硬币
        dp[0] = 0;
        // 更新dp数组
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < coins.size(); ++j) {
                if (i - coins[j] >= 0 && i - coins[j] < amount + 1) {
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount];
    }
}
