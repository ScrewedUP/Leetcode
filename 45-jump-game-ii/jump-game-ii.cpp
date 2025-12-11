class Solution {
public:
    int n;
    int solve(int i,vector<int> &nums,vector<int> &dp){
        if ( i >= n ) return 1e3;
        if ( i == n -1 ) return 0;
        if ( dp[i] != -1 ) return dp[i];
        int x = 1e4;
        for(int j = 1 ; j <= nums[i] ; j++){
            x = min(x,1+solve(i+j,nums,dp));
        }
        return dp[i] = x;
    }
    int jump(vector<int>& nums) {
        n = nums.size();
        vector<int> dp(n,-1);
        return solve(0,nums,dp);
    }
};