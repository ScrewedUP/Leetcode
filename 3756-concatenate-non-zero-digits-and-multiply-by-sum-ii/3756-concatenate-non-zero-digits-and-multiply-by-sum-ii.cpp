class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> prefixNum(n + 1, 0);
        vector<long long> prefixSum(n + 1, 0);
        vector<int> nonZeroCnt(n + 1, 0);
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;
        for (int i = 1; i <= n; i++) {
            int d = s[i - 1] - '0';

            prefixSum[i] = prefixSum[i - 1] + d;
            nonZeroCnt[i] = nonZeroCnt[i - 1] + (d != 0);

            if (d == 0)
                prefixNum[i] = prefixNum[i - 1];
            else
                prefixNum[i] = (prefixNum[i - 1] * 10 + d) % MOD;
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0] + 1;
            int r = q[1] + 1;

            long long sum = prefixSum[r] - prefixSum[l - 1];

            int nz = nonZeroCnt[r] - nonZeroCnt[l - 1];

            long long number =
                (prefixNum[r]
                - (prefixNum[l - 1] * pow10[nz]) % MOD
                + MOD) % MOD;

            ans.push_back((number * sum) % MOD);
        }

        return ans;
    }
};