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
                        int skip = dp[1][0];
                        int take = nums[0] + dp[2][1];
                        dp[0][0] = max(skip, take);
                    }
                } else if (i == n - 1) {
                    if (t == 1) {
                        dp[i][1] = dp[i + 1][1];
                    } else {
                        int skip = dp[i + 1][0];
                        int take = nums[i] + dp[i + 2][0];
                        dp[i][0] = max(skip, take);
                    }
                } else {
                    int skip = dp[i + 1][t];
                    int take = nums[i] + dp[i + 2][t];
                    dp[i][t] = max(skip, take);
                }
            }
        }
        return dp[0][0];
    }
};
