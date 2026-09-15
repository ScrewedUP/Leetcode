class Solution {
public:
    bool check(int i,int j,string &s){
        while ( i <= j){
            if ( s[i] != s[j]) return false;
            i++;j--;
        }
        return true;
    }
    int dp[2005];

int solve(int i, string &s, int k) {
    if (i >= s.size()) return 0;

    if (dp[i] != -1) return dp[i];

    int ans = solve(i + 1, s, k);

    for (int j = i + k - 1; j < s.size(); j++) {
        if (check(i, j, s)) {
            ans = max(ans, 1 + solve(j + 1, s, k));
        }
    }

    return dp[i] = ans;
}
    int maxPalindromes(string s, int k) {
        memset(dp,-1,sizeof(dp));
        if ( k == 1 ) return s.size();
        return solve(0,s,k);
    }
};