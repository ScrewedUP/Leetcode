class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        // t[i][j] defines the longest comman subsequence
        // between string1 of length i and string2 of 
        // length j
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> t(n+1,vector<int>(m+1,0));
        for(int i = 0 ; i < n ; i++){
            t[i][0] = 0;
        }
        for(int i = 0 ; i < m ; i++){
            t[0][i] = 0;
        }
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if ( text1[i-1] == text2[j-1] ){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else{
                    t[i][j] = max(t[i-1][j] , t[i][j-1]);
                }
            }
        }
        return t[n][m];
    }
};