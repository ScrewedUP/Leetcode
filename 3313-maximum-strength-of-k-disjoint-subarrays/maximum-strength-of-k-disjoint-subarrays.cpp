class Solution {
public:
    // unordered_map<vector<long long>,long long>dp;
    long long maximumStrength(vector<int>& nums, int k) {
        int n=nums.size();
        int turn=1,turn1=0;
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(k+1,vector<long long>(2,LLONG_MIN)));
        long long ans=LLONG_MIN;
        for(int i=0;i<n;++i){
            ans=max(ans,solve(0,turn1,k,nums,dp));
        }
        return ans;
    }
    long long solve(int i,int turn1,int k,vector<int>&nums,vector<vector<vector<long long>>> &dp){
        if(k==0) return 0;
        if(i==nums.size()) return -1e18;
        if(dp[i][k][turn1] != LLONG_MIN ) return dp[i][k][turn1];
        long long ans=LLONG_MIN;
        if(turn1==0){
            ans=solve(i+1,turn1,k,nums,dp);
        }else{
            ans=solve(i+1,0,k-1,nums,dp);
        }
        if(k%2 == 1){
            ans=max(ans,solve(i+1,1,k,nums,dp)+1ll*k*nums[i]);
            ans=max(ans,solve(i+1,0,k-1,nums,dp)+1ll*k*nums[i]);
        }else{
            ans=max(ans,solve(i+1,1,k,nums,dp)-1ll*k*nums[i]);
            ans=max(ans,solve(i+1,0,k-1,nums,dp)-1ll*k*nums[i]);
        }
        return dp[i][k][turn1]=ans;
    }
};