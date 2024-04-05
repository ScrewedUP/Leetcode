class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(auto it : s){
            if ( st.size() > 0 ){
                if ( st.top() - 'a' == it - 'A' || st.top() - 'A' == it - 'a'){
                    st.pop();
                }
                else st.push(it);
            }
            else st.push(it);
        }
        string ans;
        while ( !st.empty() ){
            auto ch = st.top();
            st.pop();
            ans += ch;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};