class Solution {
public:
    int minBitFlips(int start, int goal) {
        int num = start^goal;
        int cnt = 0;
        for(int i = 31 ; i >= 0 ; i--){
            if ( num & ( 1 << i) ){
                cnt++;
            }
        }
        return cnt;
    }
};