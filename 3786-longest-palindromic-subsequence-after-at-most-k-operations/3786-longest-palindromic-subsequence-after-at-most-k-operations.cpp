class Solution {
public:
    int t[201][201][201];
    int solve(int i,int j,int k,string &s){
        if ( i > j ) return 0;
        if ( i == j ) return 1;
        if ( t[i][j][k] != -1 ) return t[i][j][k];
        int ans = 0;
        if ( s[i] == s[j]){
            ans = max(ans,2 + solve(i+1,j-1,k,s));
        }
        else{
            ans = max(ans,max(solve(i+1,j,k,s),solve(i,j-1,k,s)));
            int x = min(abs(s[i] - s[j]),26-abs(s[i] - s[j]));
            if ( x <= k ){
                ans = max(ans,2 + solve(i+1,j-1,k-x,s));
            }
        }
        return t[i][j][k] = ans;
    }
    int longestPalindromicSubsequence(string s, int k) {
        memset(t,-1,sizeof(t));
        int n = s.size();
        return solve(0,n-1,k,s);
    }
};