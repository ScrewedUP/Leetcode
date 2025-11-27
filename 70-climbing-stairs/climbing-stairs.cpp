class Solution {
public:
    int t[50];
    int climbStairs(int n) {
        memset(t,0,sizeof(t));
        t[n] = 1;
        for(int i = n - 1; i >= 0 ; i--){
            t[i] = t[i+1] + t[i+2];
        }
        return t[0];
    }
};