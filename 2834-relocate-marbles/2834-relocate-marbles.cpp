class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        map<int,int> m;
        for(auto it : nums){
            m[it]++;
        }
        int n = moveFrom.size() ; 
        for(int i = 0 ; i < n ; i++){
            int x = m[moveFrom[i]];
            m.erase(moveFrom[i]);
            m[moveTo[i]]+=x;
        }
        vector<int> ans;
        for(auto it : m ){
            ans.push_back(it.first);
        }
        return ans;
    }
};