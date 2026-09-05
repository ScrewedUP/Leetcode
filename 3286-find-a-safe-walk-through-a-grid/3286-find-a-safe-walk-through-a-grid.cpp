class Solution {
public:
    int n, m;
    vector<vector<int>> vis;

    bool solve(int i, int j, int h, vector<vector<int>>& grid) {
        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;

        h -= grid[i][j];

        if (h <= 0)
            return false;

        if (i == n - 1 && j == m - 1)
            return true;

        if (vis[i][j] >= h)
            return false;

        vis[i][j] = h;

        if (solve(i - 1, j, h, grid)) return true;
        if (solve(i + 1, j, h, grid)) return true;
        if (solve(i, j - 1, h, grid)) return true;
        if (solve(i, j + 1, h, grid)) return true;

        return false;
    }

    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        n = grid.size();
        m = grid[0].size();

        vis.assign(n, vector<int>(m, -1));

        return solve(0, 0, health, grid);
    }
};