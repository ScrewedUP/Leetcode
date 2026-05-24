class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        map<int,int> m;
        vector<int> ans;
        for(int i = 0 ; i < nums.size() ; i++){
            if ( m[nums[i]] < k){
                ans.push_back(nums[i]);
                m[nums[i]]++;
            }
        }
        return ans;
    }
};