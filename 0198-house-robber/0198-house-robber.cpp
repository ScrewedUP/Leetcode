class Solution {
public:
    int dp[100005];
    int solve(int i,vector<int> &nums){
        if ( i >= nums.size()) return 0;
        if ( dp[i] != -1 ) return dp[i];
        int skip = solve(i+1,nums);
        int take = nums[i] + solve(i+2,nums);

        return dp[i] = max(skip,take);
    }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};