class Solution {
public:
    int minimumChairs(string s) {
        for(int i = 1 ; i <= 50  ; i++){
            bool ok = true;
            int cnt = 0;
            for(int j = 0 ; j < s.size() ; j++){
                if ( s[j] == 'E') cnt++;
                else cnt--;
                if ( cnt > i ){
                    ok = false;
                    break;
                }
            }
            if ( ok ) return i;
        }
        return -1;
    }
};