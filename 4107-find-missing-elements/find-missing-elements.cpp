class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        set<int> s(nums.begin(),nums.end());
        int l = nums[0];
        int r = nums.back();
        for(int i = l + 1 ; i < r ; i++){
            if ( s.find(i) == s.end() ){
                ans.push_back(i);
            }
        }
        return ans;
    }
};