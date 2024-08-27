class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& e, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>> adj;
        for(int i = 0 ; i < e.size() ; i++){
            adj[e[i][0]].push_back({e[i][1],succProb[i]});
            adj[e[i][1]].push_back({e[i][0],succProb[i]});
        }
        vector<double> ans(n,0);
        priority_queue<pair<double,int>> pq;
        pq.push({1.0,start_node});
        ans[start_node] = 1.0;
        while(!pq.empty()){
            auto tp = pq.top();
            pq.pop();
            int node = tp.second;
            double prob = tp.first;
            if ( node == end_node){
                return prob;
            } 
            for(auto it : adj[node]){
                int nd = it.first;
                double wt = it.second;
                if ( ans[nd] < wt*prob){
                    ans[nd] = wt*prob;
                    pq.push({wt*prob,nd});
                }
            }
        }
        
        return ans[end_node] <= INT_MIN ? 0.00 : ans[end_node];
    }
};