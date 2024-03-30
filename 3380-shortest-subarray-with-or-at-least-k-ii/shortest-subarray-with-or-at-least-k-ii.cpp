class Solution {
public:
    void update(vector<int>& bitsCount, int num, int increment) {
        for (int i = 0; i < 32; i++) {
            if (num & (1 << i)) {
                bitsCount[i] += increment;
            }
        }
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        int ans = 0;
        int len = INT_MAX;
        vector<int> bitsCount(32, 0);
        
        for (int right = 0; right < n; right++) {
            ans |= nums[right];
            update(bitsCount, nums[right], 1);
            
            while (ans >= k && left <= right) {
                len = min(len, right - left + 1);
                update(bitsCount, nums[left], -1);
                ans = 0; 
                //int newans = 0;
                for (int i = 31; i >= 0; i--) {
                    if (bitsCount[i] > 0) {
                        ans |= (1 << i);
                    }
                }
                // cout << newans << " " << ans << endl;
                left++;
            }
        }
        
        return len == INT_MAX ? -1 : len;
    }
};
