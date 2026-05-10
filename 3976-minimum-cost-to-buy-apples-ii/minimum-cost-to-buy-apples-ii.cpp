class Solution {
public:

    vector<long long> dijkstra(int src, vector<vector<pair<long long,long long>>> &g, int n){

        vector<long long> dist(n, LLONG_MAX);

        priority_queue<
            pair<long long,long long>,
            vector<pair<long long,long long>>,
            greater<pair<long long,long long>>
        > pq;

        dist[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){

            long long cost = pq.top().first;
            long long node = pq.top().second;
            pq.pop();

            if(cost > dist[node]) continue;

            for(auto v : g[node]){

                long long nextNode = v.first;
                long long nextCost = v.second;

                if(dist[nextNode] > cost + nextCost){

                    dist[nextNode] = cost + nextCost;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }

        return dist;
    }

    vector<int> minCost(int n, vector<int>& prices, vector<vector<int>>& roads) {

        vector<vector<pair<long long,long long>>> g1(n);
        vector<vector<pair<long long,long long>>> g2(n);

        for(int i = 0 ; i < roads.size() ; i++){

            long long u = roads[i][0];
            long long v = roads[i][1];
            long long cost = roads[i][2];
            long long tax = roads[i][3];

            g1[u].push_back({v, cost});
            g1[v].push_back({u, cost});

            g2[u].push_back({v, cost * tax});
            g2[v].push_back({u, cost * tax});
        }

        vector<int> ans;

        for(int i = 0 ; i < n ; i++){

            vector<long long> dist1 = dijkstra(i, g1, n);
            vector<long long> dist2 = dijkstra(i, g2, n);

            long long mini = prices[i];

            for(int j = 0 ; j < n ; j++){

                if(dist1[j] == LLONG_MAX || dist2[j] == LLONG_MAX) continue;

                mini = min(
                    mini,
                    dist1[j] + dist2[j] + prices[j]
                );
            }

            ans.push_back(mini);
        }

        return ans;
    }
};