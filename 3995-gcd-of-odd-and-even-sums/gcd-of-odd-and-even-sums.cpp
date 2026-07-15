class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int oc = 0 , ec = 0;
        for(int i = 1 ; i <= 2*n ; i++){
            if ( i % 2 == 0 ) oc += i;
            else ec += i;
        }

        return __gcd(oc,ec);
    }
};