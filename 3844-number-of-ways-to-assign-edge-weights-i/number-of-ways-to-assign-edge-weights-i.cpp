class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;

        while (b) {
            if (b & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    int dfs(int u, unordered_map<int, vector<int>>& g, vector<int>& vis) {
        vis[u] = 1;

        int depth = 0;

        for (int v : g[u]) {
            if (!vis[v]) {
                depth = max(depth, 1 + dfs(v, g, vis));
            }
        }

        return depth;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> g;

        for (auto& e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        int n = edges.size() + 1;

        vector<int> vis(n + 1, 0);

        int depth = dfs(1, g, vis);

        if (depth == 0)
            return 0;

        return modPow(2, depth - 1);
    }
};