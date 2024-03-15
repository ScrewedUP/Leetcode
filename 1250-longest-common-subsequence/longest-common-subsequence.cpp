class Solution {
public:
    int t[1001][1001];
    int solve(int i,int j,string &text1, string &text2){
        if ( i >= text1.size() || j >= text2.size() ) return 0;
        if ( t[i][j] != -1 ) return t[i][j];
        int take1 = 0;
        int take2 = 0;
        int take3 = 0;
        if ( text1[i] == text2[j] ){
            take1 = 1 + solve(i+1,j+1,text1,text2);
        }
        else{
            take2 = solve(i+1,j,text1,text2);
            take3 = solve(i,j+1,text1,text2);
        }
        return t[i][j] = max({take1,take2,take3});
    }
    int longestCommonSubsequence(string text1, string text2) {
        memset(t,-1,sizeof(t));
        return solve(0,0,text1,text2);
    }
};