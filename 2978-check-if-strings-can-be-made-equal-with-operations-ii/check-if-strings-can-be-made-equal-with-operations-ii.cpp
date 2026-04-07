class Solution {
public:
    bool checkStrings(string s1, string s2) {
        string a,b,c,d;
        for(int i = 0 ; i < s1.size() ; i++){
            if ( i % 2 == 0){
                a += s1[i];
                c += s2[i];
            }
            else{
                b += s1[i];
                d += s2[i];
            }
        }

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());
        sort(d.begin(),d.end());

        if ( a == c && b == d ) return true;
        return false;
    }
};