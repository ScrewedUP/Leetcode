class Solution {
public:
    int t[50];
    int f(int i,int n){
        if ( i > n ) return 0;
        if ( i == n ) return 1;
        if ( t[i] != -1 ) return t[i];
        int one = f(i+1,n);
        int two = f(i+2,n);
        return t[i] = one + two;
    }
    int climbStairs(int n) {
        memset(t,-1,sizeof(t));
        return f(0,n);
    }
};