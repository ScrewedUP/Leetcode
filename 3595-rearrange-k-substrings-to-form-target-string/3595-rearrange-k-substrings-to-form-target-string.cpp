class Solution {
public:
    bool isPossibleToRearrange(string s, string t, int k) {
        int x = s.size()/k;
        map<string,int> m;
        string temp = ""; 
        for(int i = 0 ; i < s.size() ; i++){
            temp += s[i];
            if ( temp.size() == x){
                m[temp]++;
                temp = "";
            }
        }
        map<string,int> m2;
        string temp2 = ""; 
        for(int i = 0 ; i < s.size() ; i++){
            temp2 += t[i];
            if ( temp2.size() == x){
                m2[temp2]++;
                temp2 = "";
            }
        }
        return m == m2;
    }
};