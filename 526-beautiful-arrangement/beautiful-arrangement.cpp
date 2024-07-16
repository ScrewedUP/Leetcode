class Solution {
public:
    int countArrangement(int n) {
        vector<int> dp(1 << n, 0);
        dp[0] = 1;

        for (int mask = 1; mask < (1 << n); mask++) {
            int num = __builtin_popcount(mask); 
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i) && ((i + 1) % num == 0 || num % (i + 1) == 0)) {
                    dp[mask] += dp[mask ^ (1 << i)];
                }
            }
        }

        return dp[(1 << n) - 1];
    }
};
