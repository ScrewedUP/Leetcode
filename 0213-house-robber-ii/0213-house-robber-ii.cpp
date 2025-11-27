class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int t = 0; t <= 1; t++) {
                if (i == 0) {
                    if (t == 0) {
                        dp[i][t] = max(dp[1][0], nums[0] + dp[2][1]);
                    }
                } else if (i == n - 1) {
                    if (t == 1) {
                        dp[i][t] = dp[i + 1][t];
                    } else {
                        dp[i][t] = max(dp[i + 1][t], nums[i] + dp[i + 2][t]);
                    }
                } else {
                    dp[i][t] = max(dp[i + 1][t], nums[i] + dp[i + 2][t]);
                }
            }
        }
        return dp[0][0];
    }
};
