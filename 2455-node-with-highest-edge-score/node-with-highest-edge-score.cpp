class Solution {
public:
    int edgeScore(vector<int>& edges) {
        map<int,long long> m;
        int n = edges.size();
        for(int i = 0 ; i < n ; i++){
            m[edges[i]] += i;
        }
        int node = 0;
        long long maxi = LLONG_MIN;
        for(auto it : m){
            if ( it.second > maxi ){
                maxi = it.second;
                node = it.first;
            }
        }
        return node;
    }
};