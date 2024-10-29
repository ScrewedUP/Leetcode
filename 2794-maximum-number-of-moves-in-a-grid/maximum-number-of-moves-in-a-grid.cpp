class Solution {
public:
    // ( i - 1,j + 1)
    // ( i , j + 1)
    // ( i + 1 , j + 1)
    int t[1001][1001];
    int solve(int i,int j,vector<vector<int>>& grid){
        if ( i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0 ) return 0;
        int ans = 0;
        if ( t[i][j] != -1 ) return t[i][j];
        if ( i > 0 && j < grid[0].size() - 1 && grid[i-1][j+1] > grid[i][j]){
            ans = max(ans,1 + solve(i-1,j+1,grid));
        }
        if (j < grid[0].size() - 1 && grid[i][j+1] > grid[i][j]){
            ans = max(ans,1 + solve(i,j+1,grid));
        }
        if ( i < grid.size() - 1 && j < grid[0].size() - 1 && grid[i+1][j+1] > grid[i][j]){
            ans = max(ans,1 + solve(i+1,j+1,grid));
        }
        return t[i][j] = ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
        memset(t,-1,sizeof(t));
        int ans = 0;
        int n = grid.size();
        for(int i = 0 ; i < n ; i++){
            int x = 1 + solve(i,0,grid);
            // cout << i << " " << x << endl;
            ans = max(ans,x);    
        }
        return ans - 1;
    }
};