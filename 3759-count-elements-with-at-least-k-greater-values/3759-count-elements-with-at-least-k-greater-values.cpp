class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        if (k == 0) return nums.size();

        map<int,int> m;
        for (auto x : nums) m[x]++;

        vector<int> val;
        vector<int> freq;
        for (auto it : m) {
            val.push_back(it.first);
            freq.push_back(it.second);
        }

        int n = val.size();
        vector<int> suf(n + 1);
        suf[n] = 0;
        for (int i = n - 1 ; i >= 0 ; i--) {
            suf[i] = suf[i + 1] + freq[i];
        }

        int cnt = 0;
        for (int i = 0 ; i < n ; i++) {
            int greater = suf[i + 1];
            if (greater >= k) cnt += freq[i];
        }

        return cnt;
    }
};
