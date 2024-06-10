class Solution {
public:
    long long numberOfSubstrings(string s) {
        map<char,int> m;
        for(auto it : s) m[it]++;
        long long ans = 0;
        for(auto it : m ){
            long long curr = 1;
            curr *= it.second;
            curr *= it.second + 1;
            curr /= 2;
            ans += curr;
        }
        return ans;
    }
};