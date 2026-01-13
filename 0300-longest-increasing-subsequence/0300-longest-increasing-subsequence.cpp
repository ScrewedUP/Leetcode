class Solution {
public:
    int dp[2501][2502];
    int solve(int i,int l,vector<int> &nums){
        if ( i >= nums.size() ) return 0;
        if ( dp[i][l+1] != -1 ) return dp[i][l+1];
        int skip = solve(i+1,l,nums);
        int take = 0; 
        if ( l == -1 || nums[i] > nums[l]){
            take = 1 + solve(i+1,i,nums);
        }
        return dp[i][l+1] = max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(0,-1,nums);
    }
};