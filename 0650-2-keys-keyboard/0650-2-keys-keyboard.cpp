class Solution {
public:
    int t[1001][1001];
    int solve(int c,int n,int l){
        if ( c > n ) return 1e4;
        if ( c == n ) return 0;
        if ( t[c][l] != -1 ) return t[c][l];
        int paste1 = 1 + solve(c + l,n,l);
        int paste2 = 2 + solve( c + c , n, c);
        return t[c][l] = min(paste1,paste2);
    }
    int minSteps(int n) {
        if ( n == 1 ) return 0;
        memset(t,-1,sizeof(t));
        return 1 + solve(1,n,1);
    }
};