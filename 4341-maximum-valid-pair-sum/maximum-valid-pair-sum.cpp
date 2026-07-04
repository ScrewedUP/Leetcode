class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxi(n,0);
        maxi[n-1] = nums[n-1];
        int mx = nums[n-1];
        for(int i = n - 2  ; i >= 0 ; i--){
            mx = max(mx,nums[i]);
            maxi[i] = max(nums[i],mx);
        }

        int ans = 0;
        for(int i = 0 ; i < n ; i++){
            if ( i + k >= n ) break;
            ans = max(ans,nums[i] + maxi[i+k]);
        }
        return ans;
    }
};