class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        vector<vector<int>> g(n);
        vector<int> ind(n);

        for(auto i : p){
            g[i[0]].push_back(i[1]);
            ind[i[1]]++;
        }

        queue<int> q;
        for(int i = 0 ; i < n ; i++){
            if ( ind[i] == 0 ) q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int x = q.front();q.pop();
            cnt++;
            for(auto it : g[x]){
                ind[it]--;
                if ( ind[it] == 0){
                    q.push(it);
                }
            }
        }
        if ( cnt == n ) return true;
        return false;
    }
};