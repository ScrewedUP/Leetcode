class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
    int cnt = 0;
    for (int j = 0; j < grid[0].size(); j++) {  
        for (int i = 1; i < grid.size(); i++) {
            if (grid[i][j] <= grid[i-1][j]) {
                int x = abs(grid[i][j] - grid[i-1][j]) + 1;
                cnt += x;
                grid[i][j] = grid[i-1][j] + 1;
            }
        }
    }
    return cnt;
}

};