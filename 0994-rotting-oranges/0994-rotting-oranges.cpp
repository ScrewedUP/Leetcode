class Solution {
public:
    int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) q.push({i,j});
                else if (grid[i][j] == 1) fresh++;
            }
        }

        int time = 0;

        while (!q.empty() && fresh > 0) {
            int sz = q.size();

            while (sz--) {
                auto [x,y] = q.front(); q.pop();

                for (auto &k : d) {
                    int dx = x + k[0], dy = y + k[1];

                    if (dx >= 0 && dx < n && dy >= 0 && dy < m &&
                        grid[dx][dy] == 1)
                    {
                        grid[dx][dy] = 2;
                        q.push({dx,dy});
                        fresh--;
                    }
                }
            }
            time++;
        }

        return fresh == 0 ? time : -1;
    }
};