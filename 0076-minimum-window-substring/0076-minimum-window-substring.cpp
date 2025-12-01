class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        vector<int> v(128, 0);
        for (char c : t) v[c]++;
        
        int l = 0;
        int st = 0;
        int len = INT_MAX;
        int count = t.size();
        
        for (int i = 0; i < n; i++) {
            if (v[s[i]]-- > 0) count--;
            
            while (count == 0) {
                if (i - l + 1 < len) {
                    len = i - l + 1;
                    st = l;
                }
                if (v[s[l]]++ == 0) count++;
                l++;
            }
        }
        
        return len == INT_MAX ? "" : s.substr(st, len);
    }
};
