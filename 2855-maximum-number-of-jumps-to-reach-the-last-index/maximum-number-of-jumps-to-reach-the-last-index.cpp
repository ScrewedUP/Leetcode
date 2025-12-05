class Solution {
public:
    int maximumJumps(vector<int>& a, int t) {
        int n = a.size();
        const int NEG = -100000000; 
        vector<int> dp(n, NEG);
        dp[n-1] = 0;
        for (int i = n-2; i >= 0; i--) {
            for (int j = i+1; j < n; j++) {
                int d = a[j] - a[i];
                if (d <= t && d >= -t) dp[i] = max(dp[i], 1 + dp[j]);
            }
        }
        return dp[0] < 0 ? -1 : dp[0];
    }
};
