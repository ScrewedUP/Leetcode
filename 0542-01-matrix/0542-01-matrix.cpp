class Solution {
public:
    int d[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> dis(n, vector<int>(m, INT_MAX));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    dis[i][j] = 0;
                    q.push({i,j});
                }
            }
        }

        while (!q.empty()) {
            auto [x,y] = q.front(); q.pop();

            for (auto &k : d) {
                int dx = x + k[0], dy = y + k[1];

                if (dx >= 0 && dx < n && dy >= 0 && dy < m &&
                    dis[dx][dy] > dis[x][y] + 1)
                {
                    dis[dx][dy] = dis[x][y] + 1;
                    q.push({dx,dy});
                }
            }
        }
        return dis;
    }
};