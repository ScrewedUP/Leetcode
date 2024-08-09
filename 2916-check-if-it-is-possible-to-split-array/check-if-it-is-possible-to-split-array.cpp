class Solution {
public:
    bool solve(int i ,int j,vector<int> &v,int m,vector<int> &nums,vector<vector<int>> &dp){
        if ( i == j || j - i == 1) return true;
        int sum = v[j] - (i >= 1 ? v[i-1] : 0);
        if ( sum < m && j - i > 1 ) return false;
        if ( dp[i][j] != -1 ) return dp[i][j];
        bool op1 = false;
        bool op2 = false;
        if ( sum - nums[i] >= m) op1 = solve(i+1,j,v,m,nums,dp);
        if ( sum - nums[j] >= m) op2 = solve(i,j-1,v,m,nums,dp);
        return dp[i][j]= op1 || op2;
    }
    bool canSplitArray(vector<int>& nums, int m) {
        int sum  = 0;
        for(auto it :  nums) sum += it;
        vector<int> prefix(nums.begin(),nums.end());
        for(int i = 1 ; i < nums.size() ; i++){
            prefix[i] += prefix[i-1];
        }
        vector<vector<int>> dp(nums.size() + 1,vector<int>(nums.size()+ 1,-1));
        return solve(0,nums.size() - 1,prefix,m,nums,dp);
    }
};