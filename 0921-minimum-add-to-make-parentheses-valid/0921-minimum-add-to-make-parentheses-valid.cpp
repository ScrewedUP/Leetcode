class Solution {
public:
    int minAddToMakeValid(string s) {
        int cnt = 0;
        int o = 0;
        for(int i = 0 ; i < s.size() ; i++){
            if ( s[i] == '('){
                o++;
            }
            else if ( s[i] == ')'){
                if ( o > 0) o--;
                else cnt++;
            }
        }
        cnt += o;
        return cnt;
    }
};