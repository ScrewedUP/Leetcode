class Solution {
public:
    int f(int i ,vector<int> &nums,int t,vector<int> &dp){
        if ( i >= nums.size()) return -1e3;
        if ( i == nums.size() - 1 ) return 0;
        if ( dp[i] != -1 ) return dp[i];
        int ans = -1e3;
        for(int j = i+1 ; j < nums.size() ; j++){
            if ( nums[j] - nums[i] <= t 
                && nums[j] - nums[i] >= -1*t){
                    ans = max(ans,1 + f(j,nums,t,dp));
                }
        }
        return dp[i] = ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        vector<int> dp(nums.size(),-1);
        int x = f(0,nums,target,dp);
        if ( x < 0 ) return -1; 
        return x;
    }
};