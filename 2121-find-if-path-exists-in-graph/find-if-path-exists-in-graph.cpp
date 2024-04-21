class Solution {
public:
    bool dfs(int node,int n,int target,unordered_map<int,vector<int>> &adj,vector<int> &vis){
        vis[node] = 1;
        for(auto it : adj[node]){
            if ( it == target ) return true;
            if ( vis[it] == 0){
                if ( dfs(it,n,target,adj,vis) ) return true;
                
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if ( source == destination ) return true;
        vector<int> vis(n,0);
        unordered_map<int,vector<int>> adj;
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        return dfs(source,n,destination,adj,vis);
    }
};