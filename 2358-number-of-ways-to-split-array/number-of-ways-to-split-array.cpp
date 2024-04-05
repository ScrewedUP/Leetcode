class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long cnt = 0;
        int n = nums.size();
        vector<long long> prefix(n);
        prefix[0] = nums[0];
        for(int i = 1 ; i < n ; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }
        for(int i = 0 ; i < n - 1 ; i++){
            long long curr = prefix[i];
            long long second = prefix[n-1] - prefix[i];
            if ( curr >= second ) cnt++;
        }
        return cnt;
    }
};