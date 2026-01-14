class Solution {
public:
    bool check(int k, vector<int> &nums) {
        int n = nums.size();
        if (k == 0) return true;
        int count = 1;
        vector<int> inc(n, 1);
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i-1]) count++;
            else count = 1;
            inc[i] = count;
        }
        for (int i = 2 * k - 1; i < n; i++) {
            if (inc[i] >= k && inc[i - k] >= k) {
                return true;
            }
        }
        return false;
    }

    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        int l = 1;
        int h = n / 2;
        int ans = 1;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (check(mid, nums)) { 
                ans = mid;
                l = mid + 1; 
            } else {
                h = mid - 1;
            }
        }
        return ans;
    }
};