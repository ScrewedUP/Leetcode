#define ll long long
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> m;
        int n = nums.size();
        for (int i = 0;i < n; i++){
            m[nums[i]]++;
        }
        vector<int> dp(10002);
        dp[0] = 0;
        dp[1] = m[1];
        for (int i = 2 ; i <= 10001; i++){
            dp[i] = max(dp[i-1],dp[i-2]+ m[i]*i);
        }
        return dp[10001];
    }
};