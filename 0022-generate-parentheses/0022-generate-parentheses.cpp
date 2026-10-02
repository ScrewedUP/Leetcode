class Solution {
public:
    vector<string> validParentheses;
    
    void solve(int l,int r,string s){
        if ( l == 0 && r == 0){
            validParentheses.push_back(s);

            return;
        }

        if ( l > 0){
            solve(l-1,r,s + '(');
        }

        if ( r > l){
            solve(l,r-1,s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        solve(n,n,"");

        return validParentheses;
    }
};