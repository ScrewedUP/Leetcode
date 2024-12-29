class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        map<int,int> m;
        vector<int> ans(2);
        for(auto it : grid){
            for(auto it2 : it){
                m[it2]++;
            }
        }
        for(int i = 1 ; i <= grid.size()*grid.size() ; i++){
            if ( m[i] == 0){
                ans[1] = i;
            }
            if ( m[i] == 2 ){
                ans[0] = i;
            }
        }
        return ans;
    }
};