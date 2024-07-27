class Solution {
public:
    void dijkstra(int source, vector<vector<pair<int, int>>> &adj, vector<long long> &distance) {
        const long long INF = LLONG_MAX;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> pq;

        distance[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            int u = pq.top().second;
            long long dist = pq.top().first;
            pq.pop();

            for (auto &neighbor : adj[u]) {
                int v = neighbor.first;
                int weight = neighbor.second;

                long long newDist = dist + weight;

                if (newDist < distance[v]) {
                    distance[v] = newDist;
                    pq.push({newDist, v});
                }
            }
        }
    }
    
    long long minimumCost(string &source, string &target, vector<char> &original,
                          vector<char> &changed, vector<int> &cost) {
        int N = 26;
        vector<vector<pair<int, int>>> adj(N);

        for (int i = 0; i < original.size(); i++) {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            int w = cost[i];
            adj[u].push_back({v, w});
        }

        vector<vector<long long>> shortestPaths(N, vector<long long>(N, LLONG_MAX));

        for (int i = 0; i < N; i++) {
            dijkstra(i, adj, shortestPaths[i]);
        }

        long long cnt = 0;
        bool ok = true;

        for (int i = 0; i < source.size(); i++) {
            if (source[i] == target[i]) continue;
            int s = source[i] - 'a';
            int t = target[i] - 'a';

            if (shortestPaths[s][t] == LLONG_MAX) {
                ok = false;
                break;
            } else {
                cnt += shortestPaths[s][t];
            }
        }

        if (!ok) return -1;
        return cnt;
    }
};
