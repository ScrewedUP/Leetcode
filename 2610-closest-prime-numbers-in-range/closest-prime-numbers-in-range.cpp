class Solution {
public:
    vector<bool> sieve(int n) {
        vector<bool> primes(n + 1, true);
        primes[0] = primes[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (primes[i]) {
                for (int j = i * i; j <= n; j += i)
                    primes[j] = false;
            }
        }
        return primes;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<bool> primes = sieve(right);
        vector<int> v;
        for(int i = left ; i <= right ; i++){
            if ( primes[i] == true){
                v.push_back(i);
            }
        }
        if ( v.size() < 2 ) return {-1,-1};
        pair<int,int> p;
        int diff = INT_MAX;
        for(int i = 1 ; i < v.size() ; i++){
            if ( (v[i] - v[i-1]) < diff){
                p.first = v[i-1];
                p.second = v[i];
                diff = v[i] - v[i-1];
            }
        }
        return {p.first,p.second};
    }
};