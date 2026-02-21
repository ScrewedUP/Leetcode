class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<vector<int>> g(n);
        vector<int> in(n,0);

        for(auto e : p){
            g[e[0]].push_back(e[1]);
            in[e[1]]++;
        }

        queue<int> q;
        for(int i = 0 ; i < n; i++){
            if ( in[i] == 0){
                q.push(i);
            }
        }

        vector<int> topo;

        while(!q.empty()){
            int f = q.front(); q.pop();

            topo.push_back(f);

            for(auto v : g[f]){
                in[v]--;
                if ( in[v] == 0){
                    q.push(v);
                }
            }
        }
        if ( topo.size() != n ) return {};
        reverse(topo.begin(),topo.end());
        return topo;
    }
};