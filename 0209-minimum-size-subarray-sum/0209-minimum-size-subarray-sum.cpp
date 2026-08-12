class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = INT_MAX;
        int l = 0;
        int n = nums.size();
        int sum = 0;

        for(int i = 0 ; i < n ; i++){
            sum += nums[i];

            while ( sum >= target){
                len = min(len,i-l+1);
                sum -= nums[l];
                l++;
            }
        }

        if ( len == INT_MAX) return 0;
        return len;
    }

};