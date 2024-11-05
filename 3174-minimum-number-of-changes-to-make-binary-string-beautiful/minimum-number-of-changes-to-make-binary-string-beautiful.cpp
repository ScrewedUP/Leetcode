class Solution {
public:
    int minChanges(string s) {
        int cnt = 0;
        int g = 1;
        int curr = s[0];
        for(int i = 1 ; i < s.size() ; i++){
            if ( g == 2 ){
                curr = s[i];
                g = 1;
            }
            else if ( s[i] == curr && g == 1){
                g = 2;
            }
            else if ( s[i] != curr && g == 1 ){
                cnt++;
                g = 2;
            }
        }
        return cnt;
    }
};