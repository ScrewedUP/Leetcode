class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int left = 0;
        long long sum = 1;
        if ( k == 0  || k == 1) return 0;
        for(int right = 0 ;right < nums.size() ; right++){
            sum *= nums[right];
            while ( sum >= k && left < nums.size()){
                sum/=nums[left];
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};