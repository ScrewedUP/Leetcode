class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        ans += s[0];
        int cnt = 1;
        for(int i = 1 ; i < s.size() ; i++){
            if ( s[i] == s[i-1] && cnt < 2 ){
                ans += s[i];
                cnt++;
            }
            else if ( s[i] != s[i-1]){
                ans += s[i];
                cnt = 1;
            }
        }
        return ans;
    }
};