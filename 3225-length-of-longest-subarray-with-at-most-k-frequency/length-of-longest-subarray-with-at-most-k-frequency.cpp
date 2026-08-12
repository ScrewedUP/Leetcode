class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        unordered_map<int,int> m;
        int l = 0;

        for(int i = 0 ; i < n ; i++){
            m[nums[i]]++;

            while ( m[nums[i]] > k){
                m[nums[l]]--;
                l++;
            }

            ans = max(ans,i-l+1);
        }

        return ans;
    }
};