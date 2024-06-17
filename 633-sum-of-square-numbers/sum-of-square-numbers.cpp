class Solution {
public:
    bool judgeSquareSum(int c) {
        if ( c == 0 ) return true;
        for(int i = 1 ; i <= sqrt(c) ; i++){
            if ( i*i > c ) return false;
            int req = c - i*i;
            if ( floor(sqrt(req)) == ceil(sqrt(req)) ) return true;
        }
        return false;
    }
};