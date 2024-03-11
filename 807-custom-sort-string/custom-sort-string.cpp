class Solution {
public:
    string customSortString(string order, string s) {
        map<char,int> m;
        for(auto it : s){
            m[it]++;
        }
        string ans;
        vector<int> vis(26,0);
        for(int i = 0 ; i < order.size() ; i++){
            if ( m.find(order[i]) != m.end() ){
                vis[order[i] - 'a'] = 1;
                for(int j = 0 ; j < m[order[i]] ; j++){
                    ans += order[i];
                }
            }
        }
        for(auto it : s){
            if ( vis[it-'a'] != 1 ){
                ans += it;
            }
        }
        return ans;
    }
};