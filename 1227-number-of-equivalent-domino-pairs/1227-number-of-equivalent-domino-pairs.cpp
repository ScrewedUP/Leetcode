class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& d) {
        map<pair<int,int>,int> m;
        int ans = 0;
        for(auto it : d){
            if ( it[0] > it[1]){
                swap(it[0],it[1]);
            }
            pair<int,int> rev = {it[0],it[1]};
            if ( m.find(rev) != m.end()){
                ans += m[rev];
            }
            m[rev]++;
        }
        return ans;
        
        
    }

};