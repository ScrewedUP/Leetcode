class Solution {
public:
    typedef pair<int, int> pii;

    int dijkstra(int n, vector<vector<pii>>& adj) {
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        vector<int> dist(n, INT_MAX);

        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (d > dist[u]) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        return dist[n - 1];
    }
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pii>> v(n+1);
        for(auto it : edges){
            v[it[0]].push_back({it[1],it[2]});
            v[it[1]].push_back({it[0],2*it[2]});
        }

        int ans = dijkstra(n,v);
        return ans == INT_MAX ? -1 : ans;
    }
};