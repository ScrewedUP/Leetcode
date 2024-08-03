class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<bool>> &vis,vector<vector<char>>& grid){
        if ( i >= n || j >= m || i < 0 || j < 0 || vis[i][j] || grid[i][j] == '0' ) return;
        vis[i][j] = true;
        dfs(i+1,j,n,m,vis,grid);
        dfs(i-1,j,n,m,vis,grid);
        dfs(i,j+1,n,m,vis,grid);
        dfs(i,j-1,n,m,vis,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int cnt = 0;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if ( grid[i][j] == '1' && !visited[i][j] ){
                    cnt++;
                    dfs(i,j,n,m,visited,grid);
                }
            }
        }
        return cnt;
    }
};