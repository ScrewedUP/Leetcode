class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return true;
        for (int i = 0; i < n - 1; ++i) {
            int x = nums[i];
            if (i + x >= n - 1) return true;
            if (x == 0) return false;
            int j = i + 1;
            int best = -1;
            int idx = -1;
            while (j <= i + x && j < n) {
                int reach = j + nums[j];
                if (reach > best) {
                    best = reach;
                    idx = j;
                }
                ++j;
            }
            if (idx == -1) return false;
            i = idx - 1;
        }
        return false;
    }
};
