class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();

        map<char,char> m;
        m['('] = ')';
        m['{'] = '}';
        m['['] = ']';

        for(int i = 0 ; i < n ;i++){
            if ( s[i] == ')' || s[i] == ']' || s[i] == '}'){
                if ( st.size() == 0 ) return false;
                if ( m[st.top()] != s[i]) return false;
                st.pop();
            }
            else st.push(s[i]);
        }

        return st.size() == 0;
    }
};