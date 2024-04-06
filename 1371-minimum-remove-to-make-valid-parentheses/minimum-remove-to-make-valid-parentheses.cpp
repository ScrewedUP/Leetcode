class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        vector<bool> valid(n,false);
        stack<pair<char,int>> st;
        for(int i = 0 ; i < n ; i++){
            if ( s[i] == '('){
                st.push({s[i],i});
            }    
            else if ( s[i] == ')'){
                if ( st.size() > 0 ){
                    auto top = st.top();
                    st.pop();
                    valid[top.second] = true;
                    valid[i] = true;
                }
            }
        }
        string ans;
        for(int i = 0 ; i < n ; i++){
            if ( s[i] == ')' || s[i] == '(' ){
                if ( valid[i] ) ans += s[i];
            } 
            else ans += s[i];
        }
        return ans;
    }
};