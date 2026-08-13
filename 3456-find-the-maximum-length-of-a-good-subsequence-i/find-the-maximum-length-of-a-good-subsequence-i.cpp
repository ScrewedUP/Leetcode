class Solution {
public:
    int dp[501][502][26];
    int solve(int i,int l,int t,vector<int> &nums,int &k){
        if ( i >= nums.size()){
            return 0;
        }

        if ( dp[i][l][t] != -1 ) return dp[i][l][t];
        int skip = solve(i+1,l,t,nums,k);
        int take = 0;
        if ( l == 501 || nums[i] == nums[l] || t < k){
            if ( l == 501 || nums[i] == nums[l]){
                take = 1+solve(i+1,i,t,nums,k);
            }
            else take = 1+solve(i+1,i,t+1,nums,k);
        }

        return dp[i][l][t] = max(take,skip);
    }
    int maximumLength(vector<int>& nums, int k) {
        memset(dp,-1,sizeof(dp));
        return solve(0,501,0,nums,k);
    }
};