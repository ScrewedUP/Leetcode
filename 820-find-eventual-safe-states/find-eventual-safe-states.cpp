class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> g(n);
        vector<int> out(n);
        for(int i = 0 ; i < n ; i++){
            out[i] = graph[i].size();
            for(auto v : graph[i]){
                g[v].push_back(i);
            }
        }

        queue<int> q;
        vector<int> ans;
        for(int i = 0 ; i < n ; i++){
            if ( out[i] == 0 ) q.push(i);
        }

        while(!q.empty()){
            auto f = q.front();q.pop();
            ans.push_back(f);

            for(auto it : g[f]){
                out[it]--;
                if ( out[it] == 0 ) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());return ans;
    }
};