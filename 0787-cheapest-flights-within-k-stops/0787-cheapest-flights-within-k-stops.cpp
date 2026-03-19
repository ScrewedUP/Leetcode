class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto i : flights) adj[i[0]].push_back({i[1],i[2]});
        
        vector<int> ans(n+1,INT_MAX);
        ans[src] = 0;
        
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>> pq;
        pq.push({0,0,src}); 
        
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            int stops = get<0>(x);
            int d = get<1>(x);
            int node = get<2>(x);
            if (stops > k) continue;
            for(auto v : adj[node]){
                int adjNode = v.first;
                int wt = v.second;
                if (d + wt < ans[adjNode]){
                    ans[adjNode] = d + wt;
                    pq.push({stops+1,d+wt,adjNode});
                }
            }
        }
        int x = ans[dst];
        return (x == INT_MAX ? -1 : x);
    }
};
