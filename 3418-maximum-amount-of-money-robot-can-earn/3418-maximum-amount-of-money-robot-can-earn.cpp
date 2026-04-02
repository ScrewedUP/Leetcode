class Solution {
public:
    int n,m;
    int dp[501][501][3];

    int solve(int i,int j,int p,vector<vector<int>>& v){
        if (i >= n || i < 0 || j >= m || j < 0) return -1e6;

        if (i == n-1 && j == m-1){
            if (p > 0 && v[i][j] < 0) return 0;
            return v[i][j];
        }

        if ( dp[i][j][p] != -1e9 ) return dp[i][j][p];

        int take = v[i][j] + max(solve(i+1,j,p,v), solve(i,j+1,p,v));

        int skip = INT_MIN;
        if (v[i][j] < 0 && p > 0){
            skip = max(solve(i+1,j,p-1,v), solve(i,j+1,p-1,v));
        }

        return dp[i][j][p] = max(take, skip);
    }

    int maximumAmount(vector<vector<int>>& coins) {
        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                for(int k=0;k<3;k++){
                    dp[i][j][k] = -1e9;
                }
            }
        }
        n = coins.size();
        m = coins[0].size();
        return solve(0,0,2,coins);
    }
};