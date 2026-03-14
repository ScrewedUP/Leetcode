class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> g(n);
        vector<int> ind(n,0);
        for(auto it : p){
            g[it[0]].push_back(it[1]);
            ind[it[1]]++;
        }

        queue<int> q;
        for(int i = 0 ;i < n ; i++){
            if ( ind[i] == 0){
                q.push(i);
            }
        }
        vector<int> topo;
        int cnt = 0;
        while(!q.empty()){
            int f = q.front(); q.pop();
            topo.push_back(f);
            cnt++;
            for(auto  v : g[f]){
                ind[v]--;
                if ( ind[v] == 0 ) q.push(v);
            }
        }
        reverse(topo.begin(),topo.end());
        if ( cnt == n ) return topo;
        return {};
    }
};