class Solution {
public:
    int M = 1e9 + 7;
    int mod_pow(long long a,long long b,int m){
        a = a%m;
        int res = 1;
        while ( b > 0 ){
            if ( b&1 ){
                res = (res*a)%m;
            }
            b = b >> 1;

            a = (a*a)%m;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long a = 0;
        if ( n % 2 == 1){
            a = mod_pow(5,n/2 + 1,M);
        }
        else{
            a = mod_pow(5,n/2,M);
        }
        
        long long b = mod_pow(4,n/2,M);
        
        long long ans = (a*b)%M;
        return ans;
    }
};