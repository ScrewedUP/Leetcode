class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        for(auto it : s) m[it]++;
        int cnt = 0;
        bool there = false;
        for(auto it : m ){
            if ( it.second >= 2){
                if ( it.second & 1 ){
                    cnt += it.second - 1;
                }
                else{
                    cnt += it.second;
                }
            }
            if ( it.second == 1 || it.second & 1 ) there = true;
        }
        if ( there ){
            return cnt + 1;
        }
        else return cnt;
    }
};