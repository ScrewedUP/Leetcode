class Solution {
public:
    int dp[501][501];
    int solve(int i,int j,vector<int> &nums){
        if ( i > j ) return 0;
        if ( i == j ) return nums[i];
        if ( dp[i][j] != -1 ) return dp[i][j];
        int take_left = nums[i] - solve(i+1,j,nums);
        int take_right = nums[j] - solve(i,j-1,nums);
        return dp[i][j] = max(take_left,take_right);
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        return solve(0,piles.size()-1,piles) > 0;
    }
};