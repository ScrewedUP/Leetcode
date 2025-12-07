class Solution {
public:
    bool isPrime(int x){
        if ( x <= 1 ) return false;
        if ( x == 2 ) return true;
        if ( x % 2 == 0) return false;
        for(int i = 3 ; i*i <= x ; i+=2){
            if ( x % i == 0 ) return false;
        }
        return true;
    }

    // 2 + 3 + 5 + 7 + 11 + 13 + 17 + 19 + 23
    int largestPrime(int n) {
        long long x = 2;
        long long best = 0;
        if ( n == 2 || n == 3 || n == 4) return 2;
        int i = 3;
        while(x <= n){
            if ( isPrime(i)){
                // cout << i << " ";
                x += i;
                
            }
            if ( isPrime(x) && x <= n){
                    best = x;
            }
            i++;
            
        }
        return best;

    }
};