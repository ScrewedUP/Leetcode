class Solution {
public:
    const int M = 1e9+7;
    int dp[201][201][3];
    int L;

    int solve(int z,int o,int last){
        if(z==0 && o==0) return 1;

        if(dp[z][o][last]!=-1) return dp[z][o][last];

        int ans = 0;

        if(last!=0){
            for(int k=1;k<=L && k<=z;k++)
                ans = (ans + solve(z-k,o,0))%M;
        }

        if(last!=1){
            for(int k=1;k<=L && k<=o;k++)
                ans = (ans + solve(z,o-k,1))%M;
        }

        return dp[z][o][last] = ans;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        memset(dp,-1,sizeof(dp));
        L = limit;
        return solve(zero,one,2);
    }
};