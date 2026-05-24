class Solution {
public:
    int f(char c){
        if ( c >= 'a' && c <= 'z') return 1;
        if ( c >= 'A' && c <= 'Z') return 2;
        if ( c >= '0' && c <= '9') return 3;
        if ( c == '!' || c == '@' || c == '#' || c == '$') return 5;
        return 0;
    }
    int passwordStrength(string password) {
        map<char,int> m;
        int cnt = 0;
        for(int i = 0 ; i < password.size() ; i++){
            if ( m[password[i]] == 0){
                cnt += f(password[i]);
                m[password[i]]++;
            }
        }
        return cnt;
    }
};