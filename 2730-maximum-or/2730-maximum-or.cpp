class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        long long currOr = 0;
        vector<int> v(32, 0);
        
        for (int num : nums) {
            currOr |= num;
            for (int j = 0; j < 32; j++) {
                if (num & (1 << j)) {
                    v[j]++;
                }
            }
        }
        
        long long maxi = LLONG_MIN;
        
        for (int num : nums) {
            long long curr = currOr;
            for (int j = 0; j < 32; j++) {
                if ((num & (1 << j)) && v[j] == 1) {
                    curr ^= (1 << j);
                }
            }
            long long c = (long long) num << k;
            curr |= c;
            maxi = max(maxi, curr);
        }
        
        return maxi;
    }
};
