class Solution {
public:
    int solve(int i,int o ,vector<int> &nums,int x){
        if ( i >= nums.size()){
            if ( o == x) return 1;
            return 0;
        }
        int notTake = solve(i+1,o,nums,x);
        int take = solve(i+1,o|nums[i],nums,x);
        return take + notTake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int x = 0;
        for(auto it : nums){
            x |= it;
        }
        return solve(0,0,nums,x);
    }
};