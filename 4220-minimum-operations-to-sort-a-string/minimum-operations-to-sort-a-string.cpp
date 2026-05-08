class Solution {
public:
    int minOperations(string s) {
        if ( s.size() == 2 && s.back() < s[0]) return -1;
        string t = s;
        string g = s;
        sort(g.begin(),g.end());
        if ( s == g ) return 0;
        sort(t.begin(),t.begin() + s.size() - 1);
        if ( t == g ) return 1;

        t = s;
        sort(t.begin() + 1 ,t.end());

        if ( t == g) return 1;

        t = s;
        sort(t.begin(),t.begin() + s.size() - 1);
        sort(t.begin() + 1, t.end());
        if ( t == g ) return 2;

        t = s;
        sort(t.begin() + 1, t.end());
        sort(t.begin(),t.begin() + s.size() - 1);
        if ( t == g ) return 2;
        return 3;
    }
};