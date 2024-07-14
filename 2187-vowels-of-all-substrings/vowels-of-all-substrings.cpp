class Solution {
public:
    bool isvowel(char v) {
        return (0x208222>>(v&0x1f))&1;
    }
    long long countVowels(string s) {
        long long ans = 0;
        int n = s.size();
        for(int i = 0 ; i < s.size() ; i++){
            if ( isvowel(s[i]) ){
                ans += (long long)(i+1)*(long long)(n-i);
            }
        }
        return ans;
    }
};