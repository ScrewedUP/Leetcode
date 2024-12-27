class Solution {
public:
    int findLargestSum(const vector<int>& a, const vector<int>& b) {
        int n = b.size();
        vector<int> maxSuffix(n, -1);

        maxSuffix[n - 1] = b[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            maxSuffix[i] = max(b[i], maxSuffix[i + 1]);
        }
        int largestSum = -1;
        for (int i = 0; i < a.size(); ++i) {
            if (i + 1 < n) {
                largestSum = max(largestSum, a[i] + maxSuffix[i + 1]);
            }
        }

        return largestSum;
    }

    int maxScoreSightseeingPair(vector<int>& values) {
        int n = values.size();
        vector<int> a(n),b(n);
        for(int i = 0 ; i < n ; i++){
            a[i] = values[i] + i;
            b[i] = values[i] - i;
        }
        return findLargestSum(a,b);

    }
};