class Solution {
public:
    int solve(int i ,vector<int> &nums,vector<int> &dp){
        if ( i >= nums.size()) return 0;

        if ( dp[i] != INT_MIN ) return dp[i];
        int take1 = nums[i] - solve(i+1,nums,dp);
        int take2 = -1e4;
        if ( i + 1 < nums.size()) take2 = nums[i] + nums[i+1] - solve(i+2,nums,dp);

        int take3 = -1e4;

        if ( i + 2 < nums.size()) take3 = nums[i] + nums[i+1] + nums[i+2] - solve(i+3,nums,dp);

        return dp[i] = max(take1,max(take2,take3));

    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<int> dp(stoneValue.size() + 1,INT_MIN);
        int x = solve(0,stoneValue,dp);

        if ( x > 0 ) return "Alice";
        else if ( x == 0 ) return "Tie";
        return "Bob";
    }
};