class Solution {
public:
    /*
        sort the coins in decending order then at each index i
        we can either take that and be on the same index or
        move to the next index
    */

    long long dp[13][10005];
    long long solve(int i,long long curr,vector<int> &coins,int amount){
        if ( curr == amount ) return 0;

        if ( i >= coins.size() || curr > amount ) return 1e6;
        if ( dp[i][curr] != -1 ) return dp[i][curr];
        // take and stay at this index

        long long take1 = 1 + solve(i,curr + coins[i],coins,amount);

        // take and move to the next index

        long long take2 = 1 + solve(i+1,curr + coins[i],coins,amount);

        // skip this denomination
        long long skip = solve(i+1,curr,coins,amount);

        return dp[i][curr] = min({take1,take2,skip});
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(dp,-1,sizeof(dp));
        sort(coins.begin(),coins.end());
        long long x = solve(0,0,coins,amount);
        if ( x >= 1e6 ) return -1;
        return x;
    }
};