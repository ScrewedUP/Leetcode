class Solution {
public:
    const int INF = numeric_limits<int>::max(); 
    vector<int> dijkstra(int source, const vector<vector<pair<int, int>>>& graph) { 
        int n = graph.size(); 
        vector<int> dist(n, INF); 
        dist[source] = 0; 
    
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; 
        pq.push({0, source}); 
    
        while (!pq.empty()) { 
            int curr_dist = pq.top().first; 
            int u = pq.top().second; 
            pq.pop(); 
    
           
            if (curr_dist > dist[u]) continue; 
    
            for (const auto& edge : graph[u]) { 
                int v = edge.first; 
                int weight = edge.second; 
    
                if (dist[u] + weight < dist[v]) { 
                    dist[v] = dist[u] + weight; 
                    pq.push({dist[v], v}); 
                } 
            } 
        } 
    
        return dist; 
    } 
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> graph(n); 
        for(int i = 0 ; i < n-1 ; i++){
            graph[i].emplace_back(i+1,1);
        }
        int source = 0;
        vector<int> ans;
        for(int i = 0 ; i < queries.size() ; i++){
            graph[queries[i][0]].emplace_back(queries[i][1],1);
            vector<int> distances = dijkstra(source, graph);
            ans.push_back(distances[n-1]);
        } 
        return ans;
        
    }
};