class Solution {
public:
    const int M = 1e9 + 7;
    int t[100005][3][4];
    int solve(int idx,int abs,int late,int n){
        if ( abs >= 2 || late >= 3) return 0;
        if ( idx == n ) return 1;
        if ( t[idx][abs][late] != -1 ) return t[idx][abs][late];
        int pr = 0;
        pr = solve(idx+1,abs,0,n);
        pr = (pr + solve(idx+1,abs+1,0,n))%M;
        pr = (pr + solve(idx+1,abs,late+1,n))%M;
        
        return t[idx][abs][late] = pr;
    }
    int checkRecord(int n) {
        memset(t,-1,sizeof(t));
        return solve(0,0,0,n);
    }
};