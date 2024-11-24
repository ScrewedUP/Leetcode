class Solution {
public:
    int ceil(int x, int y) {
        if (x % y == 0) {
            return x / y;
        }
        return x / y + 1;
    }
    int dp[101][101][101];
    int solve(int idx,int op1,int op2,int k , vector<int>&nums){
        if ( idx >= nums.size() ) return 0;
        if ( dp[idx][op1][op2] != -1 ) return dp[idx][op1][op2];
        int ans = INT_MAX;
        ans = min(ans,nums[idx] + solve(idx+1,op1,op2,k,nums));
        if ( op1 > 0 ){
            ans = min(ans,ceil(nums[idx],2) + solve(idx+1,op1-1,op2,k,nums));
        }
        if ( op2 > 0 && nums[idx] >= k ){
            ans = min(ans,nums[idx] - k + solve(idx+1,op1,op2-1,k,nums));
        }
        if ( op1 > 0 && op2 > 0 && (ceil(nums[idx],2) - k) >= 0){
            ans = min(ans,(ceil(nums[idx],2) - k) + solve(idx+1,op1-1,op2-1,k,nums));
        }
        if ( op1 > 0 && op2 > 0 && nums[idx] - k >= 0 && ceil(nums[idx] - k,2) >= 0){
            ans = min(ans,ceil(nums[idx] - k,2) + solve(idx+1,op1-1,op2-1,k,nums));
        }
        return dp[idx][op1][op2] = ans;

    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,op1,op2,k,nums);
    }
};