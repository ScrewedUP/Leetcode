class Solution {
public:
    vector<string> validParentheses;
    bool isValid(string s){
        stack<char> st;

        for(int i = 0 ; i < s.size() ; i++){
            if ( s[i] == ')'){
                if ( !st.empty()){
                    if ( st.top() == '('){
                        st.pop();
                    }
                    else return false;
                }
            }
            else st.push(s[i]);
        }

        return st.empty();
    }
    void solve(int l,int r,string s){
        if ( l == 0 && r == 0){
            if ( isValid(s)){
                validParentheses.push_back(s);
            }

            return;
        }

        if ( l > 0){
            solve(l-1,r,s + '(');
        }

        if ( r > 0){
            solve(l,r-1,s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        solve(n,n,"");

        return validParentheses;
    }
};