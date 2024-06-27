class Solution {
public:
    int t[4][100005];
    const int m = 1e9 + 7;
    int solve(int idx, int rem,int fours,vector<int> &v){
        if ( rem < 0 ) return 0;
        if ( rem == 0 ) return 1;
        if ( idx >= v.size() ){
            int takeFour = 0;
            if ( rem == 4 ) takeFour += 1;
            if ( rem == 8 ) takeFour += 1;
            return takeFour;
        }
        if ( t[idx][rem] != -1 ) return t[idx][rem];
        int take = solve(idx,rem-v[idx],fours,v);
        int notTake = solve(idx+1,rem,fours,v);
        
        return t[idx][rem] = (take + notTake)%m;
    }
    int numberOfWays(int n) {
        memset(t,-1,sizeof(t));
        vector<int> v = {1,2,6};
        return solve(0,n,2,v);
    }
};