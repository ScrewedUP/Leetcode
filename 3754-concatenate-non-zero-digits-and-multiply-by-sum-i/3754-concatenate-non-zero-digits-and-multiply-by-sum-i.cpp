class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        long long ans = 0;
        string t;
        string g = to_string(n);
        for(int i = 0 ;i < g.size() ; i++){
            if ( g[i] != '0'){
                t += g[i];
                sum += ( g[i] - '0');
            }
        }
        if ( t.size() == 0 ) return 0;
        long long x = stol(t);
        ans += x*sum;
        return ans;
    }
};