class Solution {
public:
    int triangleNumber(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
        vector<int> nums;
        for(auto it : nums1 ) if ( it != 0 ) nums.push_back(it);
        int ans = 0;
        int n = nums.size();
        for( int i = 0 ; i < n ; i++ ){
            for( int j = i + 1 ; j < n ; j++ ){
                int sum = nums[i] + nums[j];
                if ( sum <= 0 ) continue;
                int idx = lower_bound(nums.begin(),nums.end(),sum) - nums.begin();
                int ele = idx - j - 1;
                ans += ele;
                
            }
        }
        return ans;

    }
};