class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n + 2, vector<int>(2, 0));
        for (int i = n - 1; i >= 0; i--) {
            int skip0 = dp[i + 1][0];
            int buy = -prices[i] + dp[i + 1][1];
            dp[i][0] = max(skip0, buy);
            int skip1 = dp[i + 1][1];
            int sell = prices[i] + dp[i + 2][0];
            dp[i][1] = max(skip1, sell);
        }
        return dp[0][0];
    }
};
