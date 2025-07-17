class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) {
            return n;
        }
        vector<unordered_map<int, int>> dp(n);
        int longest = 2;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = nums[i] - nums[j];
                dp[i][diff] = dp[j].count(diff) > 0 ? dp[j][diff] + 1 : 2;
                longest = max(longest, dp[i][diff]);
            }
        }

        return longest;
    }
};
