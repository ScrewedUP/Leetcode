class Solution {
public:
    vector<int> v,p;
    int M = 1e9 + 7;
    int dp[51][1001];
    int solve(int i, int t) {
    if (t == 0) return 1;
    if (i >= v.size() || t < 0) return 0;

    if (dp[i][t] != -1) return dp[i][t];

    int ans = 0;

    for (int k = 0; k <= v[i] && k * p[i] <= t; k++) {
        ans = (ans + solve(i + 1, t - k * p[i])) % M;
    }

    return dp[i][t] = ans;
}
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        /*

            1 -> 6
            2 -> 3
            3 -> 2

        */
        memset(dp,-1,sizeof(dp));
        int n = types.size();
        v.resize(n);
        p.resize(n);    
        for(int i = 0 ; i < n ; i++){
            v[i] = types[i][0];
            p[i] = types[i][1];

        }

        int ans = solve(0,target);

        return ans;
    }
};