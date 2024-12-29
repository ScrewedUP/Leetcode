class Solution {
public:
    vector<vector<int>> permute(vector<int>& v) {
        vector<vector<int>> ans;
        sort(v.begin(),v.end());
        while(next_permutation(v.begin(), v.end())){
            ans.push_back(v);
        }
        ans.push_back(v);
        return ans;
    }
};