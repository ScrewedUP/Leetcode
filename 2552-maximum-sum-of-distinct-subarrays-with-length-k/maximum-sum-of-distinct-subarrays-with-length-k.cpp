class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long sum = 0;
        map<int,int> m;
        int l = 0;
        long long ans = 0;
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            sum += nums[i];
            m[nums[i]]++;
            int len = i - l + 1;
            if ( len == k){
                if ( m.size() == len ){
                    ans = max(ans,sum);
                }
                sum -= nums[l];
                m[nums[l]]--;

                if ( m[nums[l]] == 0 ){
                    m.erase(nums[l]);
                }
                l++;
            }
        }
        return ans;
    }
};