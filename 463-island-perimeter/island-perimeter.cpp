class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int cnt = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                int curr = 4;
                if ( grid[i][j] == 1){
                    if ( i >= 1 && grid[i-1][j] == 1 ) curr--;
                    if ( j >= 1 && grid[i][j-1] == 1 ) curr--;
                    if ( i < n-1 && grid[i+1][j] == 1 ) curr--;
                    if ( j < m - 1 && grid[i][j+1] == 1) curr--;
                    cnt += curr;
                }
            }
        }
        return cnt;
    }
};