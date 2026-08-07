class Solution {
public:
    int dp[201][40001];

    bool solve(int i, int sum, vector<int> &nums){

        if(i == nums.size())
            return sum == 20000;

        if(dp[i][sum] != -1)
            return dp[i][sum];

        bool first = solve(i + 1, sum + nums[i], nums);
        bool second = solve(i + 1, sum - nums[i], nums);

        return dp[i][sum] = first || second;
    }

    bool canPartition(vector<int>& nums) {

        memset(dp, -1, sizeof(dp));

        return solve(0, 20000, nums);
    }
};