class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        // alice draws till she has less than k points
        // prob that alice has less than or equal to
        // n points is 1 - (prob that alice has points greater 
        //                   than n)
        if (k == 0 || n >= k + maxPts) return 1.0;

        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;

        double sum = 1.0, ans = 0.0;

        for (int i = 1; i <= n; i++) {
            dp[i] = sum / maxPts;

            if (i < k) {
                sum += dp[i];
            } else {
                ans += dp[i];
            }

            if (i - maxPts >= 0) {
                sum -= dp[i - maxPts];
            }
        }

        return ans;
    }
};