class Solution {
public:
    const int M = 1e9+7;
    int dp[32][30002];
    int solve(int i,int sum,int n,int k,int t){
        if (sum > t) return 0;

        if (i == n) return sum == t;
        if ( dp[i][sum] != -1 ) return dp[i][sum];
        int ans = 0;
        for(int j = 1; j <= k; j++){
            ans = (ans + solve(i+1, sum+j, n, k, t)) % M;
        }
        return dp[i][sum] = ans;
    }

    int numRollsToTarget(int n, int k, int target) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,n,k,target);
    }
};