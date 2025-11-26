class Solution {
public:
    int n,m;
    vector<vector<int>> v;
    const int M = 1e9 + 7;
    int solve(int i, int j , int sum , int k, vector<vector<vector<int>>> &dp){
        if ( i < 0 || j < 0 || i >= n || j >= m ) return 0;
        if ( i == n - 1 && j == m - 1){
            if ( (sum + v[i][j]) % k == 0 ) return 1;
            return 0;
        }

        if ( dp[i][j][sum] != -1 ) return dp[i][j][sum];

        int r = solve(i,j+1,(sum + v[i][j])%k,k,dp);
        int d = solve(i+1,j,(sum + v[i][j])%k,k,dp);

        return dp[i][j][sum] = (r + d) % M;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,-1)));
        v = grid;
        return solve(0,0,0,k,dp);
    }
};