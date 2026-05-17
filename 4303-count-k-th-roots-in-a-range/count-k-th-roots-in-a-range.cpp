class Solution {
public:
    int countKthRoots(int l, int r, int k) {
        if ( k == 1 ) return r - l + 1;

        int x = 0;
        int cnt = 0;
        while(true){
            long long t = pow(x,k);
            if ( t >= l && t <= r){
                cnt++;
                x++;
            }
            else if ( t <= r ){
                x++;
            }
            else break;
        }
        
        return cnt;
    }
};