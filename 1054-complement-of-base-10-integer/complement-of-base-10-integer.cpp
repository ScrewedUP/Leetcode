class Solution {
public:
    /*
        1010
        1001
        n's complement is 2^k - 1 - n;
        where k is the number of bits in n
    */
    int bitwiseComplement(int n) {
        if ( n == 0 ) return 1;
        int bitCount = 0;
        int x = n;
        while( n > 0){
            bitCount++;
            n /= 2;
        }

        int mask = ( 1 << bitCount) - 1;
        return mask - x;
    }
};