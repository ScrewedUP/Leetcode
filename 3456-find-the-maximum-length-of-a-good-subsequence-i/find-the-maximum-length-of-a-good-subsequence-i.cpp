class Solution {
public:
    int dp[501][501][26];
    int solve(int idx,int last,vector<int> &nums , int k){
        if ( k < 0 ) return -1;
        if ( idx >= nums.size() ){
            return 0;
        }
        if ( last != -1 && dp[idx][last][k] != -1 ) return dp[idx][last][k];
        int take = 0;
        if ( last == -1 || nums[idx] == nums[last]){
            take = 1 + solve(idx+1,idx,nums,k);
        }
        else{
            take = 1 + solve(idx+1,idx,nums,k-1);
            
        }
        int notTake = solve(idx+1,last,nums,k);
        if ( last != -1  ) dp[idx][last][k] = max(take,notTake);
        return max(take,notTake);
    }
    int maximumLength(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        return max(1,solve(0,-1,nums,k));
    }
};
