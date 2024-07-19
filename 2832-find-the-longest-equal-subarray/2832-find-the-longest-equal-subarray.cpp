class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> m;
        for (int i = 0; i < nums.size(); ++i) {
            m[nums[i]].push_back(i);
        }

        int maxi = 0;

        for (auto& [num, indices] : m) {
            int left = 0;
            for (int right = 0; right < indices.size(); ++right) {
                while (indices[right] - indices[left] - (right - left) > k) {
                    left++;
                }
                maxi = max(maxi, right - left + 1);
            }
        }

        return maxi;
    }
};
