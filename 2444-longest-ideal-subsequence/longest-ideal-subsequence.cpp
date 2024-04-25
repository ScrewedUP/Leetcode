class Solution {
public:
    int t[100005][26];
    int solve(int idx,int prev,int k,string &s){
        if ( idx >= s.size() ) return 0;
        if ( prev != -1 && t[idx][prev] != -1 ) return t[idx][prev];
        int take = 0;
        if ( prev == -1 || abs(s[idx] - 'a' - prev) <= k){
            take = 1 + solve(idx+1,s[idx]-'a',k,s);
        }
        int notTake = solve(idx+1,prev,k,s);
        if ( prev != -1 ) t[idx][prev] = max(take,notTake);
        return max(take,notTake);
    }
    int longestIdealString(string s, int k) {
        memset(t,-1,sizeof(t));
        return solve(0,-1,k,s);
    }
};