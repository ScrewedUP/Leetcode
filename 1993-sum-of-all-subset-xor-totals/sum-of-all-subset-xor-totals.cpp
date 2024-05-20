class Solution {
public:
    int solve(int idx , vector<int> ans , vector<int> &nums){
        if ( idx >= nums.size() ){
            int curr = 0;
            for(auto it : ans){
                curr ^= it;
            }
            return curr;
        };
        ans.push_back(nums[idx]);
        int take = solve(idx+1,ans,nums);
        ans.pop_back();
        int notTake = solve(idx+1,ans,nums);

        return take+notTake;
    }
    int subsetXORSum(vector<int>& nums) {
        return solve(0,{},nums);
    }
};