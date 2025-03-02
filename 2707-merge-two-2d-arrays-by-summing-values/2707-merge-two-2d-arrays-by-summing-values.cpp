class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        map<int,int> m;
        for(auto it : nums1){
            m[it[0]] += it[1];
        }
        for(auto it : nums2){
            m[it[0]] += it[1];
        }
        vector<vector<int>> ans;
        for(auto it : m){
            vector<int> temp;
            temp.push_back(it.first);
            temp.push_back(it.second);
            ans.push_back(temp);
        }
        return ans;
    }
};