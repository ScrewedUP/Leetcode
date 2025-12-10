class Solution {
public:
    int countPermutations(vector<int>& a) {
        const int M = 1e9 + 7;
        int n = a.size();

        for (int i = 1; i < n; i++) {
            if (a[i] <= a[0]) return 0;
        }

        long long x = 1;
        for (int i = 1; i < n; i++) {
            x = (x * i) % M;
        }
        return (int)x;
    }
};
