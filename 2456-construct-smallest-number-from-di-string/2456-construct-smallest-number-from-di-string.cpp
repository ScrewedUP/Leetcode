class Solution {
public:
    string ans = "99999999999";
    bool check(string s,string p){
        bool ok = true;
        for(int i = 0 ; i < p.size() ; i++){
            if ( p[i] == 'I'){
                if ( s[i] - '0' > s[i+1] - '0'){
                    ok = false;
                    break;
                }
            }
            else{
                if ( s[i] - '0' < s[i+1] - '0'){
                    ok = false;
                    break;
                }
            }
        }
        return ok;
    }
    void solve(string s,int n,vector<int> &v,string &p){
        if ( s.size() == n + 1){
            if ( check(s,p) ){
                ans = min(s,ans);
            }
            return;
        }
        for(int i = 1 ; i <= 9 ; i++){
            if ( v[i] == 0){
                s += (i + '0');
                v[i] = 1;
                solve(s,n,v,p);
                v[i] = 0;
                s.pop_back();
            }
        }
    }
    string smallestNumber(string pattern) {
        // Can try all possible patterns and check if it satisfy
        int n = pattern.size();
        vector<int> v(10,0);
        solve("",n,v,pattern);
        return ans;
    }
};