class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0;
        map<int,int> m;
        long long maxi = 0;
        long long sum = 0;
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            m[nums[i]]++;
            if ( i - l  + 1 == k){
                if ( m.size() == k ){
                    maxi = max(maxi,sum);
                }
                sum -= nums[l];
                m[nums[l]]--;
                if ( m[nums[l]] == 0 ) m.erase(nums[l]);
                l++;
            }
        }
        return maxi;
    }
};