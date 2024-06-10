class Solution {
public:
    vector<int> longestCommonSubsequence(vector<vector<int>>& arrays) {
        int n = arrays.size();
        map<int,int> m;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < arrays[i].size() ; j++){
                m[arrays[i][j]]++;
            }
        }
        vector<int> ans;
        for(auto it : m){
            if ( it.second == n ){
                ans.push_back(it.first);
            }
        }
        return ans;
    }

};