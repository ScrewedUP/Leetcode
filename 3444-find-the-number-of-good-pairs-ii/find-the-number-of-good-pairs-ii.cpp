class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int, int> freq;
        for (auto it : nums1) {
            for (int i = 1; i * i <= it; i++) {
                if (it % i == 0) {
                    freq[i]++;
                    int div = it / i;
                    if (div != i) {
                        freq[div]++;
                    }
                }
            }
        }
        long long ans = 0;
        for (auto it : nums2) {
            if (freq.find(it * k) != freq.end()) {
                ans += freq[it * k];
            }
        }
    
        return ans;
    }
};