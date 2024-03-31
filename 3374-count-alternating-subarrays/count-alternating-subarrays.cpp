class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 1;
        long long ans = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i - 1]) cnt++;
            else cnt = 1;
            ans += cnt; 
        }
        
        return ans;
    }
};