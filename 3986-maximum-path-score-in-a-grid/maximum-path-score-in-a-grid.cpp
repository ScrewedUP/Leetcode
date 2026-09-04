class Solution {
public:
    int n, m;
    vector<vector<vector<int>>> dp;

    int solve(int i, int j, int cost, vector<vector<int>>& grid) {
        if (i >= n || j >= m || cost < 0)
            return -1e9;

        int x = (grid[i][j] > 0);

        if (cost < x)
            return -1e9;

        if (i == n - 1 && j == m - 1)
            return grid[i][j];

        if (dp[i][j][cost] != -1)
            return dp[i][j][cost];

        int right = solve(i, j + 1, cost - x, grid);
        int down = solve(i + 1, j, cost - x, grid);

        return dp[i][j][cost] =
            grid[i][j] + max(right, down);
    }

    int maxPathScore(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();

        dp.assign(n, vector<vector<int>>(
            m, vector<int>(k + 1, -1)
        ));

        int ans = solve(0, 0, k, grid);

        return ans < 0 ? -1 : ans;
    }
};