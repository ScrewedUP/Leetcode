class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<int,int> adj;
        for(auto it : roads){
            adj[it[0]]++;
            adj[it[1]]++;
        }
        vector<pair<int,int>> vp;
        for(auto it : adj){
            vp.push_back({it.second,it.first});
        }
        sort(vp.rbegin(),vp.rend());
        vector<int> imp(n,0);
        int t = n;
        for(auto it : vp){
            imp[it.second] = t;
            t--;
        }
        long long ans = 0;
        for(auto it : roads){
            ans += imp[it[0]] + imp[it[1]];
        }
        return ans;
    }
};