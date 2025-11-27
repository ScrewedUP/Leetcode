class Solution {
public:
    int climbStairs(int n) {
        vector<int> t(n+2,0);
        t[n] = 1;
        for(int i = n - 1; i >= 0 ; i--){
            t[i] = t[i+1] + t[i+2];
        }
        return t[0];
    }
};