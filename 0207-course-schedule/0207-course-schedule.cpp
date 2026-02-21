class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        /*
            if there is an edge from u -> v in this question 
            it implies that u can only be taken after v
            answer if always true unless there is a deadlock
            or cycle present

            we can detect the cycle with kahns algo ( topo sort )
        */
        vector<int> in(n,0);
        vector<vector<int>> g(n);
        for(auto it : p){
            g[it[0]].push_back(it[1]);
            in[it[1]]++;
        }

        queue<int> q;

        // starting point can be the vertices who have 0 indegree
        // we can store them in a queue

        for(int i = 0 ; i < n ; i++){
            if ( in[i] == 0){
                q.push(i);
            }
        }
        // cnt keep tracks of the node which where traversed 
        // while making the topo sort ordering
        // here instead of cnt++ we could have pushed the vertice
        // in an array which would give us the topo sort order
        int cnt = 0;
        while ( !q.empty()){
            int f = q.front(); q.pop();
            cnt++;

            for(auto v : g[f]){
                in[v]--;
                if ( in[v] == 0){
                    q.push(v);
                }
            }
        }

        return cnt == n;

        
    }
};