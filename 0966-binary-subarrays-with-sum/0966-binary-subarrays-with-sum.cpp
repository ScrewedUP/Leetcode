class Solution {
public: 
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return g(nums,goal) - g(nums,goal-1);
    }
    int g(vector<int>& nums, int goal) {
        int cnt = 0;
        int l = 0;
        int sum = 0;
        int n = nums.size();
        for(int r = 0 ; r < n ; r++){
            sum += nums[r];
            while ( sum > goal && r >= l){
                sum -= nums[l];
                l++;
            }
            cnt += ( r-l+1);
            
        }
        return cnt;
    }
};