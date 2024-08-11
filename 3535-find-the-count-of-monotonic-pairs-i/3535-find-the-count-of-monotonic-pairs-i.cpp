class Solution {
public:
    const int mod = 1e9 + 7;
    int t[2001][51];
    int solve(int index, int prev, vector<int> &nums) {
        if (index >= nums.size()) return 1;
        if (t[index][prev] != -1) return t[index][prev];

        int nxt = nums[index-1] - prev;
        long long ans = 0;
        for(int j = 0; j < nums[index] + 1; j++) {
            if (j >= prev && nums[index] - j <= nxt) {
                ans += solve(index+1, j, nums);
                
            }
        }
        ans %= mod;
        return t[index][prev] = ans;
    }

    int countOfPairs(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        long long ans = 0;
        for(int i = 0 ; i < nums[0] + 1 ; i++){
            ans += solve(1,i,nums);
            ans %= mod;
        }
       return ans;
    }
};