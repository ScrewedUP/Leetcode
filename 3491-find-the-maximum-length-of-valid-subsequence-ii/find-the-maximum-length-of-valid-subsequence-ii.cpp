class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int ans = 1;
        int n = nums.size();
        vector<vector<int>> t(k,vector<int>(n,1));
        for(int i = 1 ; i < n ; i++){
            for(int j = 0 ; j < i ; j++){
                int mod = (nums[i] + nums[j])%k;
                t[mod][i] = max(t[mod][i],t[mod][j] + 1);
                ans = max(ans,t[mod][i]);
            }
        }
        return ans;
    }
};