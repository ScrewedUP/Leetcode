#define pb push_back
class Solution {
public:
    vector<string> all;
    void solve(string s,int n){
        if ( s.size() > n ) return;
        if ( s.size() == n){
            all.push_back(s);
            return;
        }
        if ( s.size() == 0){
            s.pb('a');
            solve(s,n);
            s.pop_back();
            s.pb('b');
            solve(s,n);
            s.pop_back();
            s.pb('c');
            solve(s,n);
        }
        else{
            if ( s.back() == 'a'){
                s.pb('b');
                solve(s,n);
                s.pop_back();
                s.pb('c');
                solve(s,n);
            }
            else if ( s.back() == 'b'){
                s.pb('a');
                solve(s,n);
                s.pop_back();
                s.pb('c');
                solve(s,n);
            }
            else if ( s.back() == 'c'){
                s.pb('a');
                solve(s,n);
                s.pop_back();
                s.pb('b');
                solve(s,n);
            }
        }
    }
    string getHappyString(int n, int k) {
        solve("",n);
        if ( k > all.size() ) return "";
        return all[k-1];
    }
};