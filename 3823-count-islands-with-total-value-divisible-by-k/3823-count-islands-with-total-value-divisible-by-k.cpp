class Solution {
public:
    long long dfs(int i,int j,int n,int m,vector<vector<int>> &vis,vector<vector<int>>& grid){
        if ( i < 0 || j < 0 || i >= n || j >= m || vis[i][j] == 1 || grid[i][j] == 0) return 0;
        vis[i][j] = 1;
        long long l = dfs(i-1,j,n,m,vis,grid);
        long long u = dfs(i,j-1,n,m,vis,grid);
        long long r = dfs(i+1,j,n,m,vis,grid);
        long long d = dfs(i,j+1,n,m,vis,grid);
        return l + u + r + d + grid[i][j];
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if (grid[i][j] > 0 && vis[i][j] == 0){
                    long long ans = dfs(i,j,n,m,vis,grid);
                    // cout << ans << endl;
                    if ( ans % k == 0){
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};