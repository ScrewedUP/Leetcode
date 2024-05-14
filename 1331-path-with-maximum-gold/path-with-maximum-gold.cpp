class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxGold = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] != 0) {
                    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
                    maxGold = max(solve(grid, visited, i, j), maxGold);
                }
            }
        }
        return maxGold;
    }

    int solve(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col) {
        if (row < 0 || col < 0 || row == grid.size() || col == grid[0].size() || grid[row][col] == 0 || visited[row][col]) {
            return 0;
        }

        visited[row][col] = true;
        int up = solve(grid, visited, row - 1, col); 
        int down = solve(grid, visited, row + 1, col);
        int left = solve(grid, visited, row, col - 1);
        int right = solve(grid, visited, row, col + 1);
        int maxGold = max({ up, down, left, right }) + grid[row][col];
        visited[row][col] = false;
        return maxGold;
    }
};