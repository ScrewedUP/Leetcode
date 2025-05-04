class Solution {
public:
    int ceil(int x, int y) {
        if (x % y == 0) {
            return x / y;
        }
        return x / y + 1;
    }
    int numEquivDominoPairs(vector<vector<int>>& d) {
        map<pair<int,int>,int> m;
        int ans = 0;
        for(auto it : d){
            pair<int,int> curr = {it[0],it[1]};
            pair<int,int> rev = {it[1],it[0]};
            if ( m.find(curr) != m.end()){
                ans += m[curr];
            }
            if ( curr != rev){
                if ( m.find(rev) != m.end()){
                    ans += m[rev];
                }
            }
            
            m[curr]++;
        }
        return ans;
        
        
    }

};