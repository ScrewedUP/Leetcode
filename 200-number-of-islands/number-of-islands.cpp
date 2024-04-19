class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<char>>& grid,vector<vector<int>>& vis){
        if ( i >= n || j >= m || j < 0 || i < 0 || grid[i][j] == '0' || vis[i][j] ) return;
        vis[i][j] = 1;
        dfs(i+1,j,n,m,grid,vis);
        dfs(i-1,j,n,m,grid,vis);
        dfs(i,j+1,n,m,grid,vis);
        dfs(i,j-1,n,m,grid,vis);

    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if ( grid[i][j] == '1' && !vis[i][j]){
                    cnt++;
                    dfs(i,j,n,m,grid,vis);
                }
            }
        }
        return cnt;
    }
};