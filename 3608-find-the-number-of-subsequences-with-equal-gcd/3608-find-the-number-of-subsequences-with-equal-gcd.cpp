class Solution {
public:
    const int M = 1e9 + 7;

    int gcd(int x, int y) {
        while (y != 0) {
            int temp = y;
            y = x % y;
            x = temp;
        }
        return x;
    }
    
    long long solve(int idx, int first, int second, vector<int>& nums, vector<vector<vector<long long>>>& dp) {
        if (idx >= nums.size()) {
            return (first == second && first != 0) ? 1 : 0; 
        }

        if (dp[idx][first][second] != -1) 
            return dp[idx][first][second];

        long long skipBoth = solve(idx + 1, first, second, nums, dp);

        long long a = 0;
        if (first > 0) {
            int f = gcd(first, nums[idx]);
            a = solve(idx + 1, f, second, nums, dp);
        } 
        else if (first == 0) {
            a = solve(idx + 1, nums[idx], second, nums, dp);
        }

        long long b = 0;
        if (second > 0) {
            int s = gcd(second, nums[idx]);
            b = solve(idx + 1, first, s, nums, dp);
        } 
        else if (second == 0) {
            b = solve(idx + 1, first, nums[idx], nums, dp);
        }

        return dp[idx][first][second] = (skipBoth + a + b) % M;
    }

    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<long long>>> dp(
            n + 1,
            vector<vector<long long>>(201, vector<long long>(201, -1))
        );

        return solve(0, 0, 0, nums, dp);
    }
};
