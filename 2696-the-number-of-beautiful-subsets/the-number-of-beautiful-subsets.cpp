class Solution {
public:
    bool ok(int i,int k,int mask,vector<int> &nums){
        int curr = nums[i];
        for(int i = 0 ; i < nums.size() ; i++)
        {
            if(mask & (1<<i))
            {
                if(nums[i] + k == curr || nums[i] - k == curr) return false;
            }
        }
        return true;
    }
    int solve(int idx, int mask, vector<int> &nums, int k) {
        if (idx >= nums.size()) {
            if ( mask > 0 ) return 1;
            return 0;
        }
        
        int take = 0;
        if ( ok(idx,k,mask,nums)){
            take = solve(idx + 1, mask | (1 << idx), nums, k);
        }
        int notTake = solve(idx + 1, mask, nums, k);
        return take + notTake;
    }

    int beautifulSubsets(vector<int>& nums, int k) {
        
        return solve(0, 0, nums, k);
    }
};