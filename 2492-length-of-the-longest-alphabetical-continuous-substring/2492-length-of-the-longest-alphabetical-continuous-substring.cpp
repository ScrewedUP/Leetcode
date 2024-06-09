class Solution {
public:
    int longestContinuousSubstring(string s) {
        int ans = 1;
        int best = 1;
        for(int i = 1 ; i < s.size() ; i++){
            if ( s[i] - s[i-1] == 1 ){
                ans++;
            }
            else{
                ans = 1;
            }
            best = max(best,ans);
        }
        return best;
    }
};