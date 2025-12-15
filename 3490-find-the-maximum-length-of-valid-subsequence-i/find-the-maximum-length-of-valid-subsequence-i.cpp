class Solution {
public:
    int dp[200005][3][3];
    int f(int i,int l,int w,vector<int> &nums){
        if ( i >= nums.size() ) return 0;
        if (dp[i][l][w] != -1) return dp[i][l][w]; 
        int skip = f(i+1,l,w,nums);
        int take = 0;
        if ( l == 2){
            take = 1 + f(i+1,nums[i]%2,w,nums);
        }
        else{
            if ( l + (nums[i]%2) == w){
                take = 1 + f(i+1,nums[i]%2,w,nums);
            }
        }
        return dp[i][l][w] = max(skip,take);
    }
    int maximumLength(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int x = f(0,2,0,nums);
        int y = f(0,2,1,nums);
        int t = f(0,2,2,nums);
        int z = max(x,y);
        return max(z,t);
    }
};