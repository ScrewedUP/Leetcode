class Solution {
public:
    int dp[1001];
    int solve(int i,vector<int> &nums,int t ){
        if ( i >= nums.size()) return -1e5;
        if ( i == nums.size()-1) return 0;
        if ( dp[i] != -1 ) return dp[i];
        int ans = -1e6;
        for(int j = i + 1 ; j < nums.size() ; j++){
            if ( nums[j] - nums[i] <= t && nums[j] - nums[i] >= -t){
                ans = max(ans,1 + solve(j,nums,t));
            }
        }
        return dp[i] = ans;
    }
    int maximumJumps(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        int x = solve(0,nums,target); 
        return x >= 0 ? solve(0,nums,target) : -1;
    }
};