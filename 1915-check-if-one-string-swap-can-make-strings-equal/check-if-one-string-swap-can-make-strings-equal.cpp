class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        int a = -1;
        int b = -1;
        for(int i = 0 ; i < s1.size() ; i++){
            if ( s1[i] != s2[i] ){
                cnt++;
                if ( a == -1){
                    a = i;
                }
                else{
                    b = i;
                }
            }
        }
        if ( cnt == 0 ) return true;
        if ( cnt != 2) return false;
        swap(s1[a],s1[b]);
        if ( s1 == s2 ) return true;
        return false;
    }
};