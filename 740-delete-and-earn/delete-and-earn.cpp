#define ll long long
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int>m;
        int n= nums.size();
        for (int i=0;i<n;++i){
            m[nums[i]]++;
        }
        vector<ll>dp(1e5+1);
        dp[0]=0;
        dp[1]=m[1];
        for (int i=2;i<=1e5;++i){
            dp[i]=max(dp[i-1],dp[i-2]+1ll*m[i]*i);
        }
        return dp[1e5];
    }
};