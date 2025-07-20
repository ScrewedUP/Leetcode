class Solution {
public:
    int M = 1e9 + 7;
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int, long long> freq;
        for (auto& p : points) {
            freq[p[1]]++;
        }

        vector<long long> vals;
        for (auto& [y, cnt] : freq) {
            if (cnt >= 2) {
                vals.push_back(cnt * (cnt - 1) / 2);
            }
        }

        long long ans = 0, prefixSum = 0;
        for (long long val : vals) {
            ans = (ans + val * prefixSum)%M;
            prefixSum += val;
        }

        return (int)ans;
    }
};
