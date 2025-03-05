class Solution {
public:
    long long coloredCells(int n) {
        if ( n == 1 ) return 1;
        long long ans = 1;
        long long ne = 4;
        for(int i = 0 ; i < n - 1 ; i++){
            ans += ne;
            ne += 4;
        }
        return ans;
    }
};