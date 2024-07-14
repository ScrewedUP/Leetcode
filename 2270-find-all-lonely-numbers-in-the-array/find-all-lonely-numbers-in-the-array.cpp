class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        map<int,int> m;
        for(auto it : nums) m[it]++;
        vector<int> ans;
        for(int i = 0 ; i < nums.size() ; i++){
            int curr = nums[i];
            if ( m.find(curr) != m.end() &&  m.find(curr-1) == m.end() && m.find(curr+1) == m.end()){
                if ( m[curr] == 1 ) ans.push_back(curr);
            }
        }
        return ans;
    }
};