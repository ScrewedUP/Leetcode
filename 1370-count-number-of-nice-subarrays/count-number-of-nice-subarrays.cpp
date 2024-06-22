class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0;
        int ans = 0;
        int cnt = 0;
        int count = 0;
        for(int right = 0; right < nums.size(); right++) {
            if (nums[right] % 2 == 1) {
                cnt++;
                if (cnt == k) {
                    count = 0;
                }
            }
            while (cnt == k) {
                if (nums[left] % 2 == 1) {
                    cnt--;
                }
                left++;
                count++;
            }
            ans += count;
        }
        return ans;
    }
};
