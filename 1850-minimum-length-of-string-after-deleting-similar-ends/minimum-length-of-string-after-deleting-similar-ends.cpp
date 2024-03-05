class Solution {
public:
    int minimumLength(string s) {
        char curr = s[0];
        int i = 0;
        int j = s.size() - 1;
        while ( i < j ){
            
            if ( s[i] != s[j] && i == 0 ) break;
            else if ( s[i] == curr && s[j] == curr ) {
                while(s[i] == curr && i<=j) i++;
                while(s[j] == curr && i<=j) j--;
                
            }
            else if ( s[i] == curr ){
                i++;
            }
            else if ( s[j] == curr){
                j--;
            }
            else if ( s[i] == s[j]){
                curr = s[i];
                while(s[i] == curr && i<=j) i++;
                while(s[j] == curr && i<=j) j--;
            }
            else break;
        }
        return j-i+1 ;
    }
};