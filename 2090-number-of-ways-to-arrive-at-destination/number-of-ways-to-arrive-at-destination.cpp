class Solution {
public:
    int M = 1e9 + 7;
    int solve(int n, vector<vector<pair<int,int>>>& g, int src, int dest) {
        vector<long long> d(n,1e18), ways(n,0);
        
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;
        
        d[src] = 0;
        ways[src] = 1;
        pq.push({0, src});
        
        while(!pq.empty()){
            auto [dis, u] = pq.top(); pq.pop();
            
            if(dis > d[u]) continue;
            
            for(auto [v, w] : g[u]){
                if(d[v] > d[u] + w){
                    d[v] = d[u] + w;
                    ways[v] = ways[u]%M;
                    pq.push({d[v], v});
                }
                else if(d[v] == d[u] + w){
                    ways[v] = (ways[v] + ways[u])%M;
                }
            }
        }
        
        return ways[dest] % M;
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> g(n);
        for(auto i : roads){
            g[i[0]].push_back({i[1], i[2]});
            g[i[1]].push_back({i[0], i[2]});
        }

        return solve(n,g,0,n-1);
    }
};