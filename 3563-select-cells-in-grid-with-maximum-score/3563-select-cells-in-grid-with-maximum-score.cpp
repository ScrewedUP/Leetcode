class Solution {
public:
    int dp[101][1<<10];
    vector<int> v[101];
    int solve(int idx,int mask){
        if ( idx == 101 ) return 0;
        if ( dp[idx][mask] == -1 ){
            int ans = solve(idx+1,mask);
            for(auto j : v[idx]){
                if ( (mask&(1 << j )) == 0 ){
                    ans = max(ans,idx+solve(idx+1,mask|(1<<j)));
                }
            }
            dp[idx][mask] = ans;
        }
        return dp[idx][mask];
    }
    int maxScore(vector<vector<int>>& grid) {
        memset(dp,-1,sizeof(dp));
        for(int i = 0 ; i < 101 ; i++){
            v[i].clear();
        }
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                v[grid[i][j]].push_back(i);
            }
        }
        return solve(1,0);
    }
};