class Solution {
public:
    int solve(vector<int>& nums, int k){
        int left = 0;
        int n = nums.size();
        int ans = 0;
        map<int,int> m;
        for (int right = 0; right < n; right++) {
            m[nums[right]]++;
            while(m.size() > k) {
               m[nums[left]]--;
               if ( m[nums[left]] == 0 ) m.erase(nums[left]);
               left++;
            }
            ans += right - left + 1;
        }
        
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1); 
    }
};