class Solution {
public:
    int appendCharacters(string s, string t) {
        int i = 0;
        int j = 0;
        while ( i < s.size() && j < t.size()){
            int curr = t[j];
            while ( i < s.size() && s[i] != curr ) i++;
            if ( i < s.size() && j < s.size() ) j++;
            i++;
        }
        int ans = t.size() - j;
        return ans;

    }
};