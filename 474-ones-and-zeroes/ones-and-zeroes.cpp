class Solution {
public:
    int solve(int i,int m,int n,vector<string>& s,vector<vector<vector<int>>> &dp){
        if ( i >= s.size() ) return 0;
        if ( dp[i][m][n] != -1 ) return dp[i][m][n];
        int skip = solve(i+1,m,n,s,dp);
        int oc = 0;
        int zc = 0;
        for(auto it : s[i]){
            if ( it == '1') oc++;
            else zc++;
        }
        int take = 0;
        if ( oc <= n && zc <= m){
            take = 1 + solve(i+1, m - zc,n - oc,s,dp);
        }
        return dp[i][m][n] = max(take,skip);
    }
    int findMaxForm(vector<string>& s, int m, int n) {
        int sz = s.size();
        vector<vector<vector<int>>> dp(sz+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(0,m,n,s,dp);
    }
};