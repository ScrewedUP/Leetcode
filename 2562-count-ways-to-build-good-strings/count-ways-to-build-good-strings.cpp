class Solution {
public:
    const int M = 1e9 + 7;
    int t[100005];
    int solve(int i,int l,int h,int z,int o){
        if ( i > h ) return 0;
        if ( t[i] != -1 ) return t[i];
        int a = 0;
        int b = 0;
        if ( i + z >= l && i + z <= h ){
            a = 1 + solve(i+z,l,h,z,o);
        }
        else{
            a = solve(i+z,l,h,z,o);
        }
        if ( i + o >= l && i + o <= h ){
            b = 1 + solve(i+o,l,h,z,o);
        }
        else{
            b = solve(i+o,l,h,z,o);
        }
        return t[i] = (a + b) % M;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        memset(t,-1,sizeof(t));
        return solve(0,low,high,zero,one);
    }
};