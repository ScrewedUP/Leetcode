class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        map<int,int> m;
        for(auto it : friends) m[it]++;
        vector<int> ans;
        for(auto it : order){
            if ( m.find(it) != m.end()){
                ans.push_back(it);
            }
        } 
        return ans;
    }
};