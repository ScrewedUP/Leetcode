class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        map<int,int> m;
        for(auto it : nums ) m[it]++;
        for(auto it : m ) if ( it.second > 1 ) ans.push_back(it.first);
        return ans;
    }
};