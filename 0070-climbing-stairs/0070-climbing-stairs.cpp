class Solution {
public:
    int t[50];
    int climbStairs(int n) {
        memset(t,0,sizeof(t));
        t[0] = 1;
        t[1] = 1;
        for(int i = 2 ; i <= n ; i++){
            t[i] = t[i-1] + t[i-2];
        }
        return t[n];
    }
};