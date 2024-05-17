class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int sum  = 0;
        int left = 0;
        double ans = INT_MIN;
        for(int right = 0 ; right < nums.size() ; right++){
            sum += nums[right];
            if ( right - left + 1 == k ){
                ans = max(ans,(double)sum/k);
                sum -= nums[left];
                left++;
            }
        }
        return ans;
    }
};