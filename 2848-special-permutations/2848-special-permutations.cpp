class Solution {
public:
    int M = 1e9 + 7;
    int dp[15][1<<14 + 1];
    int solve(int prev,int curr,int mask,vector<int> &nums){
        if ( curr == nums.size() ) return 1;
        if ( dp[prev+1][mask] != -1 ) return dp[prev+1][mask];
        int ans = 0;
        for(int i = 0 ; i < nums.size() ; i++){
            if ( (mask & (1 << i)) > 0){
                continue;
            }
            if ( prev == -1 || nums[i] % nums[prev] == 0 || nums[prev] % nums[i] == 0){
                ans = (ans + solve(i,curr+1,mask | ( 1 << i), nums) ) % M;
            }
        }
        return dp[prev+1][mask] = ans%M;
        // return ans%M;
    }
    int specialPerm(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solve(-1,0,0,nums);
    }
};