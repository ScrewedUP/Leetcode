class Solution {
public:
    int n, m;

    int minTimeToReach(vector<vector<int>>& v) {
        n = v.size();
        m = v[0].size();
        vector<vector<int>> minTime(n, vector<int>(m, INT_MAX));
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;

        pq.push({0, 0, 0, 0}); 
        minTime[0][0] = 0;

        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!pq.empty()) {
            auto [t, i, j, moveCount] = pq.top();
            pq.pop();

            if (i == n - 1 && j == m - 1) return t;

            for (auto [di, dj] : directions) {
                int ni = i + di, nj = j + dj;
                if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                    int moveDuration = (moveCount % 2 == 0) ? 1 : 2;
                    int newTime;

                    if (t >= v[ni][nj]) {
                        newTime = t + moveDuration;
                    } else {
                        newTime = v[ni][nj] + moveDuration;
                    }

                    if (newTime < minTime[ni][nj]) {
                        minTime[ni][nj] = newTime;
                        pq.push({newTime, ni, nj, moveCount + 1});
                    }
                }
            }
        }
        return -1;
    }
};
