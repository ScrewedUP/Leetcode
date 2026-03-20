class Solution {
public:
    /*
        in n^2 i need to check the longest palindrome

        checking every substring take n^2 time , somehow n^3 solution is getting accepted
        need to fix that , checking palindrome has to be there , the main n^2 needs to be optimized


    */
    int dp[1001][1001];
    bool p(string &s,int i,int j){
        if ( i >= j ) return 1;

        if ( dp[i][j] != -1 ) return dp[i][j];

        if ( s[i] == s[j]){
            return dp[i][j] = p(s,i+1,j-1);
        }
        return 0;
    }
    string longestPalindrome(string s) {
        int sz = INT_MIN;
        int st = 0;
        memset(dp,-1,sizeof(dp));
        for(int i = 0 ; i < s.size() ; i++){
            for(int j = i ; j < s.size() ; j++){
                if ( p(s,i,j) == true){
                    if ( j - i + 1 > sz ){
                        sz = j - i + 1;
                        st = i;
                    }
                }
            }
        }
        return s.substr(st,sz);
    }
};