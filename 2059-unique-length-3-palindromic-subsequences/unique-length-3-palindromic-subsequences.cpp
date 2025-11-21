class Solution {
public:
    int countPalindromicSubsequence(string st) {
        vector<int> s(26,-1);
        vector<int> e(26,-1);
        for(int i = 0 ; i < st.size() ; i++){
            if ( s[st[i] - 'a'] == -1){
                s[st[i]- 'a'] = i;
            }
            e[st[i]- 'a'] = i;
        }
        int ans = 0;
        for(int i = 0 ; i < 26 ; i++){
            int start = s[i];
            int end = e[i];
            unordered_set<char> us;
            for(int j = start + 1 ; j < end ; j++){
                us.insert(st[j]);
            }
            ans += us.size();
        }
        return ans;
    }
    /*
        "bbcbaba"
        bbb
        bcb
        bab
    */
};