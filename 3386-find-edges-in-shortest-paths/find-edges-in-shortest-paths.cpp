class Solution {
public:
    vector<int> dijkstra(unordered_map<int, vector<pair<long long,long long>>>& adj, int src, int n) {
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;

        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);

        dist[src] = 0;

        pq.push({0, src});

        while(!pq.empty()) {

            long long  currWt   = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();
        
                        
            if(visited[currNode] == true) {
                continue;
            }


            for(auto adj: adj[currNode]) {
                int nextNode = adj.first;
                long long nextWt = adj.second;

                if(dist[nextNode] > currWt + nextWt) {
                    dist[nextNode] = currWt + nextWt;
                    pq.push({currWt + nextWt, nextNode});
                }
            }
            
            visited[currNode] = true;


        }

        return dist;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<pair<long long,long long>>> adj;
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int> fromSrc = dijkstra(adj,0,n);
        vector<int> fromDest = dijkstra(adj,n-1,n);
        int E = edges.size();
        vector<bool> result(E, false);
        
        for(int i = 0; i < E; i++) {
            
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            
            long long distFromSrc  = fromSrc[u]; //x
            long long distFromDest = fromDest[v]; //y
            
            if(distFromSrc + w + distFromDest == fromSrc[n-1]) {
                result[i] = true;
            }
            
            
            distFromSrc  = fromSrc[v]; //x
            distFromDest = fromDest[u]; //y
            if(distFromSrc + w + distFromDest == fromSrc[n-1]) {
                result[i] = true;
            }
            
        }
        
        return result;
    }
};